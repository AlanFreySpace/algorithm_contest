package test7;

import java.util.Scanner;

/*
 * 时间复杂度过高为O(N^2),无法通过评测
 */
public class CD54_P439_v1{
    public long getWater(int[] arr){
        long res=0;
        for(int i=1;i<arr.length-1;i++){
            int leftMax=0,rightMax=0;
            for(int j=0;j<i;j++)
                leftMax=Math.max(leftMax,arr[j]);
            for(int j=i+1;j<arr.length;j++)
                rightMax=Math.max(rightMax,arr[j]);
            res+=Math.max(Math.min(leftMax,rightMax)-arr[i],0);
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD54_P439_v1 ma=new CD54_P439_v1();
        System.out.print(ma.getWater(arr));
        sc.close();
    }
}