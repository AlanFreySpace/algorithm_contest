package test5;

import java.util.Scanner;

/*
 * 这版代码逻辑没问题，可由于取余过程的原因，不能通过测评，
 * 能通过测评的需要使用进阶的v2解法。
 * count记录数组中0的个数
 */
public class CD35_P409_v1{
    public long[] product(int[] arr,int P){
        if(arr==null||arr.length<2)
            return null;
        int count=0;
        long all=1;
        long[] res=new long[arr.length];
        for(int i=0;i<arr.length;i++){
            if(arr[i]!=0)
                all=(all*arr[i])%P;
            else
                count++;
        }
        if(count==0){
            for(int i=0;i<arr.length;i++)
                res[i]=all/arr[i];
        }
        if(count==1){
            for(int i=0;i<arr.length;i++)
                if(arr[i]==0)
                    res[i]=all;
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int P=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD35_P409_v1 ma=new CD35_P409_v1();
        long[] res=ma.product(arr,P);
        for(int i=0;i<N;i++)
            System.out.print(res[i]+" ");
        sc.close();
    }
}