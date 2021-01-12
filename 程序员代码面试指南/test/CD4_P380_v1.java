package test;

import java.util.Scanner;

public class CD4_P380_v1 {
	public static void uniquePairs3(int[] arr,int k){
        if(arr==null||arr.length<3)
            return;
        for(int i=0;i<arr.length-2;i++)
            if(i==0||arr[i-1]!=arr[i])//ѡ����Ԫ�����Ԫ�أ��������ظ���ӡ
                uniquePair2(arr,i,i+1,arr.length-1,k-arr[i]);
    }
    
	//ת��Ϊ��Ԫ������
    public static void uniquePair2(int[] arr,int f,int l,int r,int k){
        while(l<r){
            if(arr[l]+arr[r]>k)
                r--;
            else if(arr[l]+arr[r]<k)
                l++;
            else{
                if((l==f+1||arr[l-1]!=arr[l])&&arr[l]!=arr[f]&&arr[l]!=arr[r])//�����ظ���ӡ������֤�ϸ�����
                    System.out.println(arr[f]+" "+arr[l]+" "+arr[r]);
                l++;
                r--;
            }
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        sc.close();
        uniquePairs3(arr,k);
    }
}
