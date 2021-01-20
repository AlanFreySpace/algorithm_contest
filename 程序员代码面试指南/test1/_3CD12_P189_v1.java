package test1;

import java.util.Scanner;

/*
 * 暴力递归方法，会超时，最主要的过程是process
 */
public class _3CD12_P189_v1 {
	/*
	 * 依次对各面值的各种可能张数进行尝试
	 * i:对面值arr[i]进行尝试，当i==arr.length时，不是
	 * 对面值arr[i]尝试，而是递归基，判断尝试是否成功
	 * rest:要构成的钱数
	 */
	public int process(int[] arr,int i,int rest){
        if(i==arr.length)
            return rest==0?0:-1;
        int res=-1;
        for(int k=0;k*arr[i]<=rest;k++){
            int next=process(arr,i+1,rest-k*arr[i]);
            if(next!=-1)
                res=(res==-1?next+k:Math.min(next+k,res));
        }
        return res;
    }
    
    public int minCoin1(int[] arr,int aim){
        if(arr==null||arr.length==0||aim<0)
            return -1;
        return process(arr,0,aim);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int aim=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        _3CD12_P189_v1 ma=new _3CD12_P189_v1();
        System.out.println(ma.minCoin1(arr,aim));
        sc.close();
    }
}
