package test5;

import java.util.Scanner;

public class CD36_P411_v1{
    public void swap(int[] arr,int index1,int index2){
        int tmp=arr[index1];
        arr[index1]=arr[index2];
        arr[index2]=tmp;
    }
    
    /*
     * u表示当前左半部分的规模(的下标)，
     * i表示当前遍历到数组哪个位置。
     * 由于数组已经排好序，因此：
     * 若两数相等，左半部分规模不加，i加1遍历下一个位置
     * 若两数不等，左半部分规模加1，交换，然后i加1
     * 遍历下一个位置
     */
    public void adjust(int[] arr){
        int u=0;
        int i=1;
        while(i<arr.length){
            if(arr[u]!=arr[i]){
                u++;
                swap(arr,u,i);
            }
            i++;
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD36_P411_v1 ma=new CD36_P411_v1();
        ma.adjust(arr);
        for(int i=0;i<N;i++)
            System.out.print(arr[i]+" ");
        sc.close();
    }
}