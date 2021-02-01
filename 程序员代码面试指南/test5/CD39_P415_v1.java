package test5;

import java.util.Scanner;

public class CD39_P415_v1{
    public void swap(int[] arr,int index1,int index2){
        int tmp=arr[index1];
        arr[index1]=arr[index2];
        arr[index2]=tmp;
    }
    
    /*
     * l��ʾ��ǰ�ѷ��ִ�1��l����������
     * r��ʾ�ڵ�ǰ����������ܷ���1��r����������
     */
    public int minValue(int[] arr){
        int l=0;
        int r=arr.length;
        while(l<r){
        	/*
        	 * λ��l������ӦΪl+1
        	 */
            if(arr[l]==l+1)
                l++;
            /*
             * ������� lλ���ϵ�ǰ���ֲ����ܳ������κ�һ��λ���ϣ�
             * ���ѳ����ڶ�Ӧarr[a[l]-1]λ���ϣ����ظ�����˸��Ǽ���
             */
            else if(arr[l]<l+1||arr[l]>r||arr[l]==arr[arr[l]-1])
                arr[l]=arr[--r];
            /*
             * lλ���ϵ�ǰ����Ӧ������arr[a[l]-1]λ����,���
             * ��������
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
