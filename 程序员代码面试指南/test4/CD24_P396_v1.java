package test4;

import java.util.Scanner;

/*
 * 达到的效果：所有的偶数下标都是偶数或者所有的奇数下标都是奇数
 */
public class CD24_P396_v1 {
	public void swap(int[] arr,int index1,int index2){
        int tmp=arr[index1];
        arr[index1]=arr[index2];
        arr[index2]=tmp;
    }
    
    public void modify(int[] arr){
        int even=0,odd=1,end=arr.length-1;
        while(even<=end&&odd<=end){
            if(arr[end]%2==0){
                swap(arr,even,end);
                even+=2;
            }
            else{
                swap(arr,odd,end);
                odd+=2;
            }
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD24_P396_v1 ma=new CD24_P396_v1();
        ma.modify(arr);
        for(int i=0;i<N;i++)
            System.out.print(arr[i]+" ");
        sc.close();
    }
}
