package test7;

import java.util.Scanner;

/*
 * 通过预处理数组，将时间复杂度降为O(N)，
 * 不过引入的leftMax和rightMax数组使得空间复杂度升至
 * O(N)，还有进一步优化的方法见v3
 */
public class CD54_P439_v2{
    public long getWater(int[] arr){
        int[] leftMax=new int[arr.length];
        leftMax[0]=arr[0];
        for(int i=1;i<arr.length;i++)
            leftMax[i]=Math.max(leftMax[i-1],arr[i]);
        int[] rightMax=new int[arr.length];
        rightMax[arr.length-1]=arr[arr.length-1];
        for(int i=arr.length-2;i>=0;i--)
            rightMax[i]=Math.max(rightMax[i+1],arr[i]);
        long res=0;
        for(int i=1;i<arr.length-1;i++)
            res+=Math.max(Math.min(leftMax[i-1],rightMax[i+1])-arr[i],0);
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD54_P439_v2 ma=new CD54_P439_v2();
        System.out.print(ma.getWater(arr));
        sc.close();
    }
}