package test1;

import java.util.Scanner;

//利用空间压缩技巧，使得空间复杂度降为O(aim)
public class _3CD12_P189_v3 {
	public int minCoin3(int[] arr,int aim){
        if(arr==null||arr.length==0||aim<0)
            return -1;
        int N=arr.length;
        int[] dp=new int[aim+1];
        dp[0]=0;
        for(int i=1;i<=aim;i++)
            dp[i]=-1;
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<=aim;j++){
                int down=dp[j];
                dp[j]=-1;
                if(down!=-1)
                    dp[j]=down;
                if(j-arr[i]>=0&&dp[j-arr[i]]!=-1){
                    if(dp[j]==-1)
                        dp[j]=dp[j-arr[i]]+1;
                    else
                        dp[j]=Math.min(dp[j],dp[j-arr[i]]+1);
                }
            }
        }
        return dp[aim];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int aim=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        _3CD12_P189_v3 ma=new _3CD12_P189_v3();
        System.out.println(ma.minCoin3(arr,aim));
        sc.close();
    }
}
