package test5;

import java.util.Scanner;

/*
 * ����ͳ�Ƶķ�����ɸ��⣬�������������ַ���������ɶѽ��
 * ��������
 */
public class CD37_P411_v1{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] count=new int[3];
        int a;
        for(int i=0;i<N;i++){
            a=sc.nextInt();
            if(a==0)
                count[0]++;
            else if(a==1)
                count[1]++;
            else
                count[2]++;
        }
        for(int i=0;i<3;i++)
            for(int j=0;j<count[i];j++)
                System.out.print(i+" ");
        sc.close();
    }
}