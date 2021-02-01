package test5;

import java.util.Scanner;

public class CD39_P415_v1{
    public void swap(int[] arr,int index1,int index2){
        int tmp=arr[index1];
        arr[index1]=arr[index2];
        arr[index2]=tmp;
    }
    
    /*
     * l表示当前已发现从1到l的连续整数
     * r表示在当前情况下最优能发现1到r的连续整数
     */
    public int minValue(int[] arr){
        int l=0;
        int r=arr.length;
        while(l<r){
        	/*
        	 * 位置l的数字应为l+1
        	 */
            if(arr[l]==l+1)
                l++;
            /*
             * 这种情况 l位置上当前数字不可能出现在任何一个位置上，
             * 或已出现在对应arr[a[l]-1]位置上，即重复，因此覆盖即可
             */
            else if(arr[l]<l+1||arr[l]>r||arr[l]==arr[arr[l]-1])
                arr[l]=arr[--r];
            /*
             * l位置上当前数字应出现在arr[a[l]-1]位置上,因此
             * 交换即可
             */
            else
                swap(arr,l,arr[l]-1);
        }
        return l+1;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD39_P415_v1 ma=new CD39_P415_v1();
        System.out.print(ma.minValue(arr));
        sc.close();
    }
}
