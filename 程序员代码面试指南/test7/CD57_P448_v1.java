package test7;

import java.util.Scanner;

/*
 * 注意右移一位，即<<1，相当于除以2
 * 另外：
 * >>>是不带符号的右移运算符，将运算符左边的对象向
 * 右移动运算符指定的位数，并且在高位补0。
 * >>是带符号的右移运算符，将运算符左边的对象向右移动
 * 运算符指定的位数。如果是正数，高位补0；如果是负数，
 * 则在高位补1。
 * 对于正数来说，两者没有区别。
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