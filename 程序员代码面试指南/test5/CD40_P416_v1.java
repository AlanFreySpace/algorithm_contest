package test5;

import java.util.Scanner;

public class CD40_P416_v1{
    public int maxGap(int[] arr){
        int len=arr.length; 
        int max=Integer.MIN_VALUE;
        int min=Integer.MAX_VALUE;
        for(int i=0;i<len;i++){
            max=Math.max(arr[i],max);
            min=Math.min(arr[i],min);
        }
        if(max==min)
            return 0;
        boolean[] hasNum=new boolean[len+1]; //len+1个桶，表示各桶中是否有数
        int[] mins=new int[len+1]; //各桶中最大数
        int[] maxs=new int[len+1]; //各桶中最小数
        for(int i=0;i<len;i++){
            int bid=bucketNum(arr[i],len,max,min);
            mins[bid]=(hasNum[bid]?Math.min(mins[bid],arr[i]):arr[i]);
            maxs[bid]=(hasNum[bid]?Math.max(maxs[bid],arr[i]):arr[i]);
            hasNum[bid]=true;
        }
        /*
         * cmax即当前遍历桶中最大的数，因为我们知道
                  *  最大差值一定在中间隔有空桶的情况下产生，因此i
                  *  的下标从1开始 
         */
        int cmax=maxs[0]; 
        int res=0;
        for(int i=1;i<=len;i++){
            if(hasNum[i]){
                res=Math.max(mins[i]-cmax,res);
                cmax=maxs[i];
            }
        }
        return res;
    }
    
    /*
     * 使用long类型防止相乘时溢出
     */
    public int bucketNum(long num,long len,long max,long min){
        return (int)((num-min)*len/(max-min));
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD40_P416_v1 ma=new CD40_P416_v1();
        System.out.print(ma.maxGap(arr));
        sc.close();
    }
}