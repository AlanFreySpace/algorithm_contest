package test6;

import java.util.Scanner;

/*
 * 未采用空间压缩方法时的动态规划
 */
public class CD43_P230_v1{
    public int minCost(String str1,String str2,int ic,int dc,int rc){
        char[] c1=str1.toCharArray();
        char[] c2=str2.toCharArray();
        int[][] dp=new int[c1.length+1][c2.length+1];
        for(int i=1;i<=c2.length;i++)
            dp[0][i]=i*ic;
        for(int i=1;i<=c1.length;i++)
            dp[i][0]=i*dc;
        for(int i=1;i<=c1.length;i++)
            for(int j=1;j<=c2.length;j++){
                dp[i][j]=Math.min(dp[i-1][j]+dc,dp[i][j-1]+ic);
                dp[i][j]=Math.min(c1[i-1]==c2[j-1]?dp[i-1][j-1]:dp[i-1][j-1]+rc,dp[i][j]);
            }
        return dp[c1.length][c2.length];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String str1=sc.next();
        String str2=sc.next();
        int ic=sc.nextInt();
        int dc=sc.nextInt();
        int rc=sc.nextInt();
        CD43_P230_v1 ma=new CD43_P230_v1();
        System.out.print(ma.minCost(str1,str2,ic,dc,rc));
        sc.close();
    }
}
