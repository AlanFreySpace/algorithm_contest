package test7;

import java.util.PriorityQueue;
import java.util.Scanner;

/*
 * ����̰�Ĳ��ԣ�ÿ�ζ�ȡ������С���ȣ���Ӧ�ֽ�����С���ѣ�
 * ʵ���ϸ����ǹ���������ı���
 */
public class CD51_P421_v1{
    public long getMinCost(long[] arr){
        PriorityQueue<Long> len=new PriorityQueue<Long>();
        for(int i=0;i<arr.length;i++)
            len.add(arr[i]);
        long ans=0,sum=0;
        while(len.size()!=1){
            sum=len.poll()+len.poll();
            ans+=sum;
            len.add(sum);
        }
        return ans;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        long[] arr=new long[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD51_P421_v1 ma=new CD51_P421_v1();
        System.out.print(ma.getMinCost(arr));
        sc.close();
    }
}
