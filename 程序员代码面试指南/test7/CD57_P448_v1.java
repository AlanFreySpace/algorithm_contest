package test7;

import java.util.Scanner;

/*
 * ע������һλ����<<1���൱�ڳ���2
 * ���⣺
 * >>>�ǲ������ŵ���������������������ߵĶ�����
 * ���ƶ������ָ����λ���������ڸ�λ��0��
 * >>�Ǵ����ŵ���������������������ߵĶ��������ƶ�
 * �����ָ����λ�����������������λ��0������Ǹ�����
 * ���ڸ�λ��1��
 * ����������˵������û������
 */
public class CD57_P448_v1{
    public long rightOne(long n){
        long res=0;
        while(n!=0){
            n>>=1;
            res+=n;
        }
        return res;
    }
    
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        long N=sc.nextLong();
        CD57_P448_v1 ma=new CD57_P448_v1();
        System.out.print(ma.rightOne(N));
        sc.close();
    }
}