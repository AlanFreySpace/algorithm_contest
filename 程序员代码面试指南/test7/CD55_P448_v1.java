package test7;

import java.util.Scanner;

/*
 * 注意辗转相除法求最大公约数的步骤
 */
public class CD55_P448_v1{
    public int gcd(int m,int n){
        return n==0?m:gcd(n,m%n);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int M=sc.nextInt();
        int N=sc.nextInt();
        CD55_P448_v1 ma=new CD55_P448_v1();
        System.out.print(ma.gcd(M,N));
        sc.close();
    }
}