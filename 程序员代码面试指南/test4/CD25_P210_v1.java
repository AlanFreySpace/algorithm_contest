package test4;

import java.util.Scanner;

public class CD25_P210_v1 {
	/*
	 * �õ��Ը�λ��Ԫ�ؽ�β�����������������dp[]��
	 * ���Ӷ�O(N^2),�ᳬʱ
	 */
	public int[] getdp1(int[] arr){
        int[] dp=new int[arr.length];
        dp[0]=1;
        for(int i=1;i<arr.length;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i])
                    dp[i]=Math.max(dp[i],dp[j]+1);
            }
        }
        return dp;
    }
    
	/*
	 * ��������dp[],�ɹ���������������
	 */
    public int[] getLIS(int[] dp,int[] arr){
        int len=0;
        int index=0;
        for(int i=0;i<dp.length;i++){
        	/*
        	 * �˴���=��Ϊ��ȷ������ж���𰸣�
        	 * ����������ֵ�����С�ġ�
        	 */
            if(len<=dp[i]){
                len=dp[i];
                index=i;
            }
        }
        int[] lis=new int[len];
        lis[--len]=arr[index];
        for(int i=index-1;i>=0;i--){
            if(dp[i]+1==dp[index]&&arr[i]<arr[index]){
                lis[--len]=arr[i];
                index=i;
            }
        }
        return lis;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD25_P210_v1 ma=new CD25_P210_v1();
        int[] lis=ma.getLIS(ma.getdp1(arr),arr);
        for(int i=0;i<lis.length;i++)
            System.out.print(lis[i]+" ");
        sc.close();
    }
}
