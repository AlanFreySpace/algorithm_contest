package test5;

import java.util.Scanner;

public class CD32_P402_v1 {
	public double getMaxProduct(double[] arr){
        double max=arr[0],min=arr[0],res=arr[0];
        double maxEnd=0,minEnd=0;
        for(int i=1;i<arr.length;i++){
            maxEnd=max*arr[i];
            minEnd=min*arr[i];
            max=Math.max(Math.max(maxEnd,minEnd),arr[i]);
            min=Math.min(Math.min(maxEnd,minEnd),arr[i]);
            res=Math.max(max,res);
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        double[] arr=new double[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextDouble();
        CD32_P402_v1 ma=new CD32_P402_v1();
        /*
         * 注意在Java中控制double类型保留两位小数输出的方法
         * 注意是printf，不是print
         */
        System.out.printf("%.2f",ma.getMaxProduct(arr));
        sc.close();
    }
}
