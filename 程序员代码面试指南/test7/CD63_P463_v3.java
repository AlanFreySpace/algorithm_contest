package test7;

import java.util.Scanner;

/*
 * 时间复杂度均达到最优的O(N),空间复杂度达到最优的O(1)，
 * 思路巧妙，注意该题与P439CD54的容器盛水问题很像。
 */
public class CD63_P463_v3{
    public int maxABS(int[] arr){
        int max=Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++)
            max=Math.max(max,arr[i]);
        int res=max-Math.min(arr[0],arr[arr.length-1]);
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD63_P463_v3 ma=new CD63_P463_v3();
        System.out.print(ma.maxABS(arr));
        sc.close();
    }
}