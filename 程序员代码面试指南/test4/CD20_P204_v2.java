package test4;

import java.util.Scanner;

/*
 * 动态规划解法，和递归大同小异，
 * 动态规划解法先填对角线，再从
 * 下到上，从左到右填表
 */
public class CD20_P204_v2 {
	public int getMaxScore(int[] arr){
        if(arr==null||arr.length==0)
            return 0;
        int N=arr.length;
        int[] help=new int[N+2];
        help[0]=1;
        help[N+1]=1;
        for(int i=1;i<=N;i++)
            help[i]=arr[i-1];
        
        int[][] dp=new int[N+2][N+2];
        for(int i=1;i<=N;i++)
            dp[i][i]=help[i-1]*help[i]*help[i+1];
        for(int i=N-1;i>0;i--){
            for(int j=i+1;j<=N;j++){
                int finalL=help[i-1]*help[i]*help[j+1]+dp[i+1][j];
                int finalR=help[i-1]*help[j]*help[j+1]+dp[i][j-1];
                dp[i][j]=Math.max(finalR,finalL);
                for(int k=i+1;k<j;k++)
                    dp[i][j]=Math.max(dp[i][j],
                                help[i-1]*help[k]*help[j+1]+dp[i][k-1]+dp[k+1][j]);
            }
        }
        return dp[1][N];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD20_P204_v2 ma=new CD20_P204_v2();
        System.out.print(ma.getMaxScore(arr));
        sc.close();
    }
}
