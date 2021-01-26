package test4;

import java.util.Scanner;

/*
 * 暴力递归解法，体现贪心的策略
 */
public class CD20_P204_v1 {
	public int process(int[] arr,int L,int R){
        if(L==R)
            return arr[L-1]*arr[L]*arr[R+1];
        int res=Math.max(arr[L-1]*arr[L]*arr[R+1]+process(arr,L+1,R),
                        arr[L-1]*arr[R]*arr[R+1]+process(arr,L,R-1));
        for(int i=L+1;i<R;i++)
            res=Math.max(res,
            arr[L-1]*arr[i]*arr[R+1]+process(arr,L,i-1)+process(arr,i+1,R));
        return res;
    }
    
    public int getMaxScore(int[] arr){
        if(arr==null||arr.length==0)
            return 0;
        int N=arr.length;
        int[] helpArr=new int[N+2];
        helpArr[0]=1;
        helpArr[N+1]=1;
        for(int i=1;i<N+1;i++)
            helpArr[i]=arr[i-1];
        return process(helpArr,1,N);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD20_P204_v1 ma=new CD20_P204_v1();
        System.out.print(ma.getMaxScore(arr));
        sc.close();
    }
}
