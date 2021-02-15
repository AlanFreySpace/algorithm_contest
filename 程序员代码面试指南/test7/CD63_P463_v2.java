package test7;

import java.util.Scanner;

/*
 * 利用预处理数组的方法将时间复杂度降为O(N),但空间复杂度
 * 升至O(N)
 */
public class CD63_P463_v2{
    public int maxABS(int[] arr){
        int[] lArr=new int[arr.length-1];
        lArr[0]=arr[0];
        for(int i=1;i<arr.length-1;i++)
            lArr[i]=Math.max(lArr[i-1],arr[i]);
        int[] rArr=new int[arr.length-1];
        rArr[arr.length-2]=arr[arr.length-1];
        for(int i=arr.length-3;i>=0;i--)
            rArr[i]=Math.max(rArr[i+1],arr[i+1]);
        int res=Integer.MIN_VALUE;
        for(int i=0;i<arr.length-1;i++)
            res=Math.max(res,Math.abs(lArr[i]-rArr[i]));
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD63_P463_v2 ma=new CD63_P463_v2();
        System.out.print(ma.maxABS(arr));
        sc.close();
    }
}