package test1;

import java.util.Scanner;

/*
 * 动态规划的空间压缩形式，注意如何压缩
 * 降低了空间复杂度
 */
public class _2CD17_P192_v3 {
	private static final int MOD = (int) (1E9 + 7);
    public int way3(int N,int M,int K,int P){
        if(N<2||M<1||M>N||K<1||P<1||P>N)
            return 0;
        int[] dp=new int[N+1];
        for(int i=1;i<=N;i++)
            dp[i]=0;
        dp[P]=1;
        for(int i=1;i<=K;i++){
            int lastEle=dp[1]; //利用lastEle和
            for(int j=1;j<=N;j++){
                int tmp=dp[j];//tmp进行压缩
                if(j==1)
                    dp[j]=dp[2];
                else if(j==N)
                    dp[j]=lastEle;
                else
                    dp[j]=(lastEle+dp[j+1])%MOD;
                lastEle=tmp;
            }
        }
        return dp[M];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int K=sc.nextInt();
        int P=sc.nextInt();
        _2CD17_P192_v3 ma=new _2CD17_P192_v3();
        int ans=ma.way3(N,M,K,P);
        System.out.println(ans);
        sc.close();
    }
}
