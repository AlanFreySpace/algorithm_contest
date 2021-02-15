package test7;

import java.util.Scanner;

//利用StringBuilder加快输出
public class CD60_P456_v2{
    public static StringBuilder sb=new StringBuilder();
    public void process(int i,int N,boolean down){
        if(i>N)
            return;
        process(i+1,N,true);
        sb.append((down?"down":"up")+"\n");
        process(i+1,N,false);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        CD60_P456_v2 ma=new CD60_P456_v2();
        ma.process(1,N,true);
        System.out.print(sb.toString());
        sc.close();
    }
}