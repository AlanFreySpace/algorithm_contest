package test4;

import java.util.Scanner;

/*
 * �Ա������ϸ��֤��������397ҳ��д�ģ������е�trick��
 */
public class CD26_P397_v1 {
	public int maxSum(int[] arr){
        int cur=0,max=Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++){
            cur+=arr[i];
            max=Math.max(max,cur);
            cur=(cur<0?0:cur);
        }
        return max;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD26_P397_v1 ma=new CD26_P397_v1();
        System.out.print(ma.maxSum(arr));
        sc.close();
    }
}
