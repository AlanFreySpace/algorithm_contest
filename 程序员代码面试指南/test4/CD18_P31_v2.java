package test4;

import java.util.Scanner;

/*
 * ֻ�����������ʵĽⷨ����Ȼ�����ϸ��Ӷ�ΪO(N^2),������
 * ͦ��ġ�
 */
public class CD18_P31_v2 {
	public int getNum(int[] arr,int num){
        int res=0;
        for(int i=0;i<arr.length;i++){
            int nmin=arr[i];
            int nmax=arr[i];
            for(int j=i;j<arr.length;j++){
                nmin=Math.min(nmin,arr[j]);
                nmax=Math.max(nmax,arr[j]);
                if(nmax-nmin<=num)
                    res++;
                else
                    break; //�˴��������ʶ�����Ҫ���ǣ�
            }
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int num=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD18_P31_v2 ma=new CD18_P31_v2();
        System.out.print(ma.getNum(arr,num));
        sc.close();
    }
}
