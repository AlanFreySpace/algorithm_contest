package test4;

import java.util.Scanner;

/*
 * 动态规划第一版代码
 */
public class CD19_P199_v3 {
	public int getNum(int[] arr,int aim){
        if(arr==null||arr.length==0)
            return 0;
        int[][] dp=new int[arr.length][aim+1];
        for(int i=0;i<arr.length;i++)
            dp[i][0]=1;
        for(int i=0;i*arr[0]<=aim;i++)
            dp[0][i*arr[0]]=1;
        for(int i=1;i<arr.length;i++){
            for(int j=1;j<=aim;j++){
                int num=0;
                for(int k=0;k*arr[i]<=j;k++)
                    num=num+dp[i-1][j-k*arr[i]];
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
        CD19_P199_v3 ma=new CD19_P199_v3();
        System.out.print(ma.getNum(arr,aim));
        sc.close();
    }
}
