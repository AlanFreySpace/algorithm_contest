package test4;

import java.util.Scanner;

/*
 * 注意写1000000007,不要写10E9+7等，会出错
 * 更优化的动态规划解法。
 */
public class CD19_P199_v4 {
	public int getNum(int[] arr,int aim){
        if(arr==null||arr.length==0||aim<0)
            return 0;
        int[][] dp=new int[arr.length][aim+1];
        for(int i=0;i<arr.length;i++)
            dp[i][0]=1;
        for(int i=0;i*arr[0]<=aim;i++)
            dp[0][i*arr[0]]=1;
        for(int i=1;i<arr.length;i++){
            for(int j=1;j<=aim;j++){
                int num=dp[i-1][j];
                num=(num+(j-arr[i]>=0?dp[i][j-arr[i]]:0))%1000000007;
                dp[i][j]=num;
            }
        }
        return dp[arr.length-1][aim];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int aim=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD19_P199_v4 ma=new CD19_P199_v4();
        System.out.print(ma.getNum(arr,aim));
        sc.close();
    }
}
