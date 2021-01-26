package test4;

import java.util.Scanner;

/*
 * 用交换的方式做
 */
public class CD23_P394_v2 {
	public void sort1(int[] arr){
        int tmp=0;
        for(int i=0;i<arr.length;i++){
            while(arr[i]!=i+1){
                tmp=arr[arr[i]-1];
                arr[arr[i]-1]=arr[i];
                arr[i]=tmp;
            }
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD23_P394_v2 ma=new CD23_P394_v2();
        ma.sort1(arr);
        for(int i=0;i<N;i++)
            System.out.print(arr[i]+" ");
        sc.close();
    }
}
