package test;

import java.util.Scanner;

//��ָ�����ָ�벻�����м�ѹ���ķ�����ʱ�临�Ӷ�O(N),�ռ�O(1)
public class CD3_P380_v1 {
	public static void uniquePair(int[] arr,int k){
        if(arr==null||arr.length<2)
            return;
        int left=0;
        int right=arr.length-1;
        while(left<right){
            if(arr[left]+arr[right]>k)
                right--;
            else if(arr[left]+arr[right]<k)
                left++;
            else{
            	//�����ӡ�ظ��Ķ�Ԫ��
                if(left==0||arr[left]!=arr[left-1])
                    System.out.println(arr[left]+" "+arr[right]);
                left++;
                right--;
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
        uniquePair(arr,k);
        sc.close();
    }
}
