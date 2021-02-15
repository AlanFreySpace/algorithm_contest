package test7;

import java.util.Scanner;

public class CD60_P456_v1{
    public void process(int i,int N,boolean down){
        if(i>N)
            return;
        process(i+1,N,true);//遍历第i+1层的右子树
        System.out.println(down?"down":"up");//遍历第i层中间节点
        process(i+1,N,false);//遍历第i+1层的左子树
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        CD60_P456_v1 ma=new CD60_P456_v1();
        ma.process(1,N,true);
        sc.close();
    }
}
