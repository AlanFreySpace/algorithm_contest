package test1;

import java.util.Scanner;

/*
 * 采用动态规划的方法，未空间压缩，
 * 时间，空间复杂度均为O(N*aim)
 */
public class _3CD12_P189_v2 {
	public int minCoin2(int[] arr,int aim){
        if(arr==null||arr.length==0||aim<0)
            return -1;
        int N=arr.length;
        int[][] dp=new int[N+1][aim+1];
        dp[N][0]=0;
        /*
         * 动态规划表从最后一行填起，表中各项代表：
         * 利用该行及以下各行对应面值的货币构成该列
         * 所需钱数需要的最少货币数。
         */
        //最后一行是平凡情况，首先填好
        for(int i=1;i<=aim;i++)
            dp[N][i]=-1;
        //从下到上，从左到右填表
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<=aim;j++){
                dp[i][j]=-1; //首先初始化为-1(代表无效)
                /*
                 * 若下一行有效(不是-1)，可将要用货币数
                 * 更新为不利用货币面值i，而利用i及以下
                 * 的货币所需的货币数
                 */
                if(dp[i+1][j]!=-1)
                    dp[i][j]=dp[i+1][j];
                /*
                 * 尝试引入货币面值i，引入一张即可，因为
                 * 引入多张的最好情况已在dp[i][j-arr[i]]
                 * 中尝试过。
                 */
                if(j-arr[i]>=0&&dp[i][j-arr[i]]!=-1){
                    if(dp[i][j]==-1)
                        dp[i][j]=dp[i][j-arr[i]]+1;
                    else
                        dp[i][j]=Math.min(dp[i][j-arr[i]]+1,dp[i][j]);
                }
            }
        }
        return dp[0][aim];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int aim=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        _3CD12_P189_v2 ma=new _3CD12_P189_v2();
        System.out.println(ma.minCoin2(arr,aim));
        sc.close();
    }
}
