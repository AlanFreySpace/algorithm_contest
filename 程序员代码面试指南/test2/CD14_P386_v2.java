package test2;

import java.util.Scanner;

/*
 * �ڶ����㷨��ʱ�临�Ӷ�ΪO(N)
 */
public class CD14_P386_v2 {
	public int maxLength1(int[] arr,int k){
		/*
		 * ����������������:
		 * minSum,minSumEnd
		 */
        int[] minSum=new int[arr.length];
        int[] minSumEnd=new int[arr.length];
        minSum[arr.length-1]=arr[arr.length-1];
        minSumEnd[arr.length-1]=arr.length-1;
        for(int i=arr.length-2;i>=0;i--){
            if(minSum[i+1]<=0){
                minSum[i]=arr[i]+minSum[i+1];
                minSumEnd[i]=minSumEnd[i+1];
            }
            else{
                minSum[i]=arr[i];
                minSumEnd[i]=i;
            }
        }
        
        /*
         * Ҫע�������end,i�����壬��Ҫд��
         */
        int end=0;
        int sum=0;
        int res=0;
        for(int i=0;i<arr.length;i++){
            while(end<arr.length&&sum+minSum[end]<=k){
                sum+=minSum[end];
                end=minSumEnd[end]+1;
            }
            res=Math.max(res,end-i);
            if(end>i)
                sum-=arr[i];
            else
                end++;
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int k=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD14_P386_v2 ma=new CD14_P386_v2();
        System.out.println(ma.maxLength1(arr,k));
        sc.close();
    }
}
