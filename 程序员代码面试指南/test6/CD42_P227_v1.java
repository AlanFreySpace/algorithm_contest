package test6;

import java.util.HashMap;
import java.util.Scanner;

public class CD42_P227_v1{
	/*
	 * dp[i]存放子数组[0,i]最多可划分几个异或和为0子数组
	 * map：key存放异或和，value存放异或和出现的位置
	 */
    public int getNum(int[] arr){
        int[] dp=new int[arr.length];
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        map.put(0,-1); //重要
        dp[0]=(arr[0]==0?1:0);
        map.put(arr[0],0);
        int eor=arr[0];
        for(int i=1;i<arr.length;i++){
            eor^=arr[i]; //异或运算
            if(map.containsKey(eor)){
                int preIndex=map.get(eor);
                dp[i]=(preIndex==-1?1:dp[preIndex]+1);
            }
            dp[i]=Math.max(dp[i-1],dp[i]);
            map.put(eor,i);
        }
        return dp[arr.length-1];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD42_P227_v1 ma=new CD42_P227_v1();
        System.out.print(ma.getNum(arr));
        sc.close();
    }
}