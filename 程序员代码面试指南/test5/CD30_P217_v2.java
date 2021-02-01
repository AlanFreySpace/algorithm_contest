package test5;

import java.util.Scanner;

/*
 * �ݹ鷽������װ溺ŵ�����⣬����ͨ����ȫ����������
 * ���ڲ���ʱ��ջ�ռ�Ĵ�С�ˡ����ڵݹ鷽����ռ�ø����
 * ջ�ռ䣬�Ӷ����ջ�����StackOverflowError
 */
public class CD30_P217_v2 {
	public int process(int[] arr,int i,int from,int mid,int to){
        if(i==-1)
            return 0;
        if(arr[i]==from)
            return process(arr,i-1,from,to,mid);
        else if(arr[i]==mid)
            return -1;
        else{
            int res=process(arr,i-1,mid,from,to);
            if(res==-1)
                return -1;
            /*
             * �˴�ע���������ȼ���1<<i+res�ȼ���1<<(i+res),
             * �Ӻŵ��������ȼ���λ���㼴<<�����ȼ���
             */
            return ((1<<i)+res)%1000000007;
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD30_P217_v2 ma=new CD30_P217_v2();
        System.out.print(ma.process(arr,arr.length-1,1,2,3));
        sc.close();
    }
}
