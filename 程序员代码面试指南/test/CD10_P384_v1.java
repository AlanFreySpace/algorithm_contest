package test;

import java.util.HashMap;
import java.util.Scanner;

/*
 * 本质与CD9题完全相同，只是需要将数组进行一步预处理，
 * 然后这里k固定为0，其他完全相同
 */
public class CD10_P384_v1 {
	public int maxLength1(int[] arr){
        if(arr==null||arr.length==0)
            return 0;
        for(int i=0;i<arr.length;i++){
            if(arr[i]<0)
                arr[i]=-1;
            else if(arr[i]>0)
                arr[i]=1;
        }
        
        int sum=0,len=0;
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        map.put(0,-1);
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            if(map.containsKey(sum))
                len=Math.max(len,i-map.get(sum));
            if(!map.containsKey(sum))
                map.put(sum,i);
        }
        return len;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD10_P384_v1 ma=new CD10_P384_v1();
        System.out.println(ma.maxLength1(arr));
        sc.close();
    }
}
