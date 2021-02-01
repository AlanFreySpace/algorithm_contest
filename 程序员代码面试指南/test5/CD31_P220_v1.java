package test5;

import java.util.Scanner;

/*
 * 用动态规划的方法解决最长公共子序列问题
 */
public class CD31_P220_v1 {
	public int[][] getdp(char[] str1,char[] str2){
        int m=str1.length,n=str2.length;
        int[][] dp=new int[m][n];
        dp[0][0]=(str1[0]==str2[0]?1:0);
        for(int i=1;i<n;i++)
            dp[0][i]=Math.max(dp[0][i-1],str1[0]==str2[i]?1:0);
        for(int i=1;i<m;i++)
            dp[i][0]=Math.max(dp[i-1][0],str2[0]==str1[i]?1:0);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                if(str1[i]==str2[j])
                    dp[i][j]=Math.max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
        return dp;
    }
    
    public String getlcse(String s1,String s2){
        char[] c1=s1.toCharArray();
        char[] c2=s2.toCharArray();
        int[][] dp=getdp(c1,c2);
        int m=c1.length-1,n=c2.length-1;
        char[] res=new char[dp[m][n]];
        int index=res.length-1;
        while(index>=0){
            if(n>0&&dp[m][n]==dp[m][n-1])
                n--;
            else if(m>0&&dp[m][n]==dp[m-1][n])
                m--;
            else{
                res[index--]=c1[m];
                m--;
                n--;
            }
        }
        return String.valueOf(res);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s1=sc.next();
        String s2=sc.next();
        CD31_P220_v1 ma=new CD31_P220_v1();
        String res=ma.getlcse(s1,s2);
        if(res.equals(""))
            System.out.print(-1);
        else
            System.out.print(res);
        sc.close();
    }
}
