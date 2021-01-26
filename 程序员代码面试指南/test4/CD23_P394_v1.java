package test4;

import java.util.Scanner;
/*
 * ���������о����ã�û��ץסʵ�ʣ�arr[next-1]=next
 * ���൱��ֱ�Ӹ�ֵ��
 * next��ʾ��һ��Ӧת����λ��
 * tmp��ʾ��һ��Ӧת����λ����ԭ���Ĵ����ֵ
 */
public class CD23_P394_v1 {
	public void sort1(int[] arr){
        int tmp=0,next=0;
        for(int i=0;i<arr.length;i++){
            next=arr[i];
            while(arr[i]!=i+1){
                tmp=arr[next-1];
                arr[next-1]=next;
                next=tmp;
            }
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD23_P394_v1 ma=new CD23_P394_v1();
        ma.sort1(arr);
        for(int i=0;i<N;i++)
            System.out.print(arr[i]+" ");
        sc.close();
    }
}
