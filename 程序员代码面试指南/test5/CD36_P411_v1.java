package test5;

import java.util.Scanner;

public class CD36_P411_v1{
    public void swap(int[] arr,int index1,int index2){
        int tmp=arr[index1];
        arr[index1]=arr[index2];
        arr[index2]=tmp;
    }
    
    /*
     * u��ʾ��ǰ��벿�ֵĹ�ģ(���±�)��
     * i��ʾ��ǰ�����������ĸ�λ�á�
     * ���������Ѿ��ź�����ˣ�
     * ��������ȣ���벿�ֹ�ģ���ӣ�i��1������һ��λ��
     * ���������ȣ���벿�ֹ�ģ��1��������Ȼ��i��1
     * ������һ��λ��
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