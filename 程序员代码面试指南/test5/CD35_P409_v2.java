package test5;

import java.util.Scanner;

/*
 * 不需使用除法的解法，注意要保持数字时刻都不越界，
 * 因此res和tmp都声明为long类型
 */
public class CD35_P409_v2{
    public long[] product(int[] arr,int P){
        if(arr==null||arr.length<2)
            return null;
        long[] res=new long[arr.length];
        res[0]=arr[0];
        for(int i=1;i<arr.length;i++)
            res[i]=(res[i-1]*arr[i])%P;
        long tmp=1;
        for(int i=arr.length-1;i>0;i--){
            res[i]=(res[i-1]*tmp)%P;
            tmp=(tmp*arr[i])%P;
        }
        res[0]=tmp;
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int P=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD35_P409_v2 ma=new CD35_P409_v2();
        long[] res=ma.product(arr,P);
        for(int i=0;i<N;i++)
            System.out.print(res[i]+" ");
        sc.close();
    }
}
