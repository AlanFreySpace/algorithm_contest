package test7;

import java.util.Scanner;

public class CD60_P456_v1{
    public void process(int i,int N,boolean down){
        if(i>N)
            return;
        process(i+1,N,true);//������i+1���������
        System.out.println(down?"down":"up");//������i���м�ڵ�
        process(i+1,N,false);//������i+1���������
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        CD60_P456_v1 ma=new CD60_P456_v1();
        ma.process(1,N,true);
        sc.close();
    }
}
