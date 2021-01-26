package test4;

import java.util.Scanner;

/*
 * ���ö��ֲ��Ҿֲ���С��λ�ã�
 * Ӧ��һ������Զ��ֵ���⣺
 * ���ֲ�������Ϊ[l,r],��Ԫ��һ���ڵ�������
 * Ԫ��һ�����ڵ�λ��Ҫ�ٳ�������r=m-1,������r=m,
 * l=m+1,������l=m����ʼֵҲ��l=1,r=N-2��������l=0,r=N-1
 * ���CD25�⣬v2�����һ�����
 */
public class CD28_P401_v1 {
	public int getPoi(int[] arr){
        int N=arr.length;
        if(arr==null||N==0)
            return -1;
        if(N==1||arr[0]<arr[1])
            return 0;
        if(arr[N-1]<arr[N-2])
            return N-1;
        int l=1,r=N-2,m=0;
        while(l<r){
            m=(l+r)/2;
            if(arr[m]>arr[m-1])
                r=m-1;
            else if(arr[m]>arr[m+1])
                l=m+1;
            else
                return m;
        }
        return l;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD28_P401_v1 ma=new CD28_P401_v1();
        System.out.print(ma.getPoi(arr));
        sc.close();
    }
}
