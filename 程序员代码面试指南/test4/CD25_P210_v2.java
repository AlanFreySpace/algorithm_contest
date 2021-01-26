package test4;

import java.util.Scanner;

/*
 * 利用二分，时间复杂度仅为O(N*log N),基于以下观察：
 * 最长递增子序列各位置元素都要相对较小。
 */
public class CD25_P210_v2 {
	public int[] getdp2(int[] arr){
        int[] dp=new int[arr.length];
        int[] ends=new int[arr.length];
        int l=0,r=0,m=0,right=0;
        ends[0]=arr[0];
        dp[0]=1;
        for(int i=1;i<arr.length;i++){
            l=0;
            r=right;
            while(l<=r){
                m=(l+r)/2;
                if(ends[m]<arr[i])
                    l=m+1;
                else
                    r=m-1;
            }
            right=Math.max(right,l);
            ends[l]=arr[i];
            dp[i]=l+1;
        }
        return dp;
    }
    
    public int[] getLIS(int[] dp,int[] arr){
        int len=0;
        int index=0;
        for(int i=0;i<dp.length;i++){
            if(len<=dp[i]){
                len=dp[i];
                index=i;
            }
        }
        int[] lis=new int[len];
        lis[--len]=arr[index];
        for(int i=index-1;i>=0;i--){
            if(dp[i]+1==dp[index]&&arr[i]<arr[index]){
                lis[--len]=arr[i];
                index=i;
            }
        }
        return lis;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD25_P210_v2 ma=new CD25_P210_v2();
        int[] lis=ma.getLIS(ma.getdp2(arr),arr);
        for(int i=0;i<lis.length;i++)
            System.out.print(lis[i]+" ");
        sc.close();
    }
}
