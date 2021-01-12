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
         * 键值对(key,value),其中key是关键字，即各sum值，
         * value是值，即该sum值第一次出现的位置
         */
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            /*
             * containsKey方法用于判断map是否包含该关键字，
             * get方法用于得到关键字sum-k所对应的value值
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
