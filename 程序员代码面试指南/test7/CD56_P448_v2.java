package test7;

import java.util.Scanner;

/*
 * 通过观察规律，可将复杂度降为O(log N)
 */
public class CD56_P448_v2{
    public long zeroNum(long n){
        long res=0;
        while(n!=0){
            res+=n/5;
            n/=5;
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        long N=sc.nextLong();
        CD56_P448_v2 ma=new CD56_P448_v2();
        System.out.print(ma.zeroNum(N));
        sc.close();
    }
}
