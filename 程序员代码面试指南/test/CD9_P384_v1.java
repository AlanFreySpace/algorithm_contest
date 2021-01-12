package test;

import java.util.HashMap;
import java.util.Scanner;

public class CD9_P384_v1 {
	public int maxLength(int[] arr,int k){
        if(arr==null||arr.length==0)
            return 0;
        int sum=0,len=0;
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        map.put(0,-1);
        /*
         * ��ֵ��(key,value),����key�ǹؼ��֣�����sumֵ��
         * value��ֵ������sumֵ��һ�γ��ֵ�λ��
         */
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            /*
             * containsKey���������ж�map�Ƿ�����ùؼ��֣�
             * get�������ڵõ��ؼ���sum-k����Ӧ��valueֵ
             */
            if(map.containsKey(sum-k))
                len=Math.max(len,i-map.get(sum-k));
            if(!map.containsKey(sum))
                map.put(sum,i);
        }
        return len;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int k=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD9_P384_v1 ma=new CD9_P384_v1();
        System.out.println(ma.maxLength(arr,k));
        sc.close();
    }
}
