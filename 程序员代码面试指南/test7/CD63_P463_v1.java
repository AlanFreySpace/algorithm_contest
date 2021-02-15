package test7;

import java.util.Scanner;

/*
 * 时间复杂度过高，为O(N^2),无法通过测评
 */
public class CD63_P463_v1{
    public int maxABS(int[] arr){
        int maxLeft=0,maxRight=0;
        for(int i=0;i<arr.length-1;i++){
            maxLeft=Integer.MIN_VALUE;
            for(int j=0;j<=i;j++)
                maxLeft=Math.max(maxLeft,arr[j]);
            maxRight=Integer.MIN_VALUE;
            for(int j=i+1;j<arr.length;j++)
                maxRight=Math.max(maxRight,arr[j]);
        }
        return Math.abs(maxLeft-maxRight);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD63_P463_v1 ma=new CD63_P463_v1();
        System.out.print(ma.maxABS(arr));
        sc.close();
    }
}