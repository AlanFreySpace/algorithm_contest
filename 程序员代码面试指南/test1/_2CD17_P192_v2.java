package test1;

import java.util.Scanner;

//将暴力递归转化成动态规划
public class _2CD17_P192_v2 {
	private static final int MOD = (int) (1E9 + 7);
    public int way2(int N,int M,int K,int P){
        if(N<2||M<1||M>N||K<1||P<1||P>N)
            return 0;
        int[][] dp=new int[K+1][N+1];
        for(int i=1;i<=N;i++)
            dp[0][i]=0;
        dp[0][P]=1;
        for(int i=1;i<=K;i++)
            for(int j=1;j<=N;j++){
                if(j==1)
                    dp[i][j]=dp[i-1][2];
                else if(j==N)
                    dp[i][j]=dp[i-1][N-1];
                else
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
            }//这里就可能溢出，所以这里就取模，而不是等到最后再取模
        return dp[K][M];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int K=sc.nextInt();
        int P=sc.nextInt();
        _2CD17_P192_v2 ma=new _2CD17_P192_v2();
        int ans=ma.way2(N,M,K,P);
        System.out.println(ans);
        sc.close();
    }
}
