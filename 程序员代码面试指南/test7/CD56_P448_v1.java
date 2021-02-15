package test7;

import java.util.Scanner;

/*
 * ��ͳ���ж��ٸ�����5�ķ������Ӷ�ΪO(N*log N)���ᳬʱ
 */
public class CD56_P448_v1{
    public long zeroNum(long n){
        long res=0,cur=0;
        for(int i=5;i<=n;i+=5){
            cur=i;
            while(cur%5==0){
                res++;
                cur/=5;
            }
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        long N=sc.nextLong();
        CD56_P448_v1 ma=new CD56_P448_v1();
        System.out.print(ma.zeroNum(N));
        sc.close();
    }
}