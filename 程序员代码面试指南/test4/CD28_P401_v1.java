package test4;

import java.util.Scanner;

/*
 * 利用二分查找局部最小的位置，
 * 应进一步加深对二分的理解：
 * 二分查找区间为[l,r],是元素一定在的区间里
 * 元素一定不在的位置要刨除。所以r=m-1,而不是r=m,
 * l=m+1,而不是l=m，初始值也是l=1,r=N-2，而不是l=0,r=N-1
 * 结合CD25题，v2代码进一步理解
 */
public class CD28_P401_v1 {
	public int getPoi(int[] arr){
        int N=arr.length;
        if(arr==null||N==0)
            return -1;
        if(N==1||arr[0]<arr[1])
            return 0;
        if(arr[N-1]<arr[N-2])
            return N-1;
        int l=1,r=N-2,m=0;
        while(l<r){
            m=(l+r)/2;
            if(arr[m]>arr[m-1])
                r=m-1;
            else if(arr[m]>arr[m+1])
                l=m+1;
            else
                return m;
        }
        return l;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD28_P401_v1 ma=new CD28_P401_v1();
        System.out.print(ma.getPoi(arr));
        sc.close();
    }
}
