package test6;

import java.util.Scanner;

/*
 * 利用动态规划解决字符串的交错组成问题，但未
 * 空间压缩，空间复杂度较大
 */
public class CD44_P233_v1{
    public boolean isCross(String str1,String str2,String aim){
        char[] c1=str1.toCharArray();
        char[] c2=str2.toCharArray();
        char[] ac=aim.toCharArray();
        if(c1.length+c2.length!=ac.length)
            return false;
        boolean[][] dp=new boolean[c1.length+1][c2.length+1];
        dp[0][0]=true;
        for(int i=1;i<=c1.length;i++){
            if(c1[i-1]!=ac[i-1])
                break;
            dp[i][0]=true;
        }
        for(int i=1;i<=c2.length;i++){
            if(c2[i-1]!=ac[i-1])
                break;
            dp[0][i]=true;
        }
        for(int i=1;i<=c1.length;i++)
            for(int j=1;j<=c2.length;j++)
                if((dp[i-1][j]==true&&c1[i-1]==ac[i+j-1])||(dp[i][j-1]==true&&c2[j-1]==ac[i+j-1]))
                    dp[i][j]=true;
        return dp[c1.length][c2.length];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String str1=sc.next();
        String str2=sc.next();
        String aim=sc.next();
        CD44_P233_v1 ma=new CD44_P233_v1();
        if(ma.isCross(str1,str2,aim)==true)
            System.out.print("YES");
        else
            System.out.print("NO");
        sc.close();
    }
}