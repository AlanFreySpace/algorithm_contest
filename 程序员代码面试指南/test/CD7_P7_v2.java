package test;

import java.util.Scanner;

public class CD7_P7_v2 {
	//Ͷ��ȡ�ɵİ취��û�н�ջ
	public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] a=new int[N];
        for(int i=0;i<N;i++)
            a[N-i-1]=sc.nextInt();
        for(int i=0;i<N;i++)
            System.out.print(a[i]+" ");
        sc.close();
    }
}
