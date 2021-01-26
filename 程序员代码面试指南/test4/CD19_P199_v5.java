package test4;

import java.util.Scanner;

//¼ÓÈë¿Õ¼äÑ¹Ëõ
public class CD19_P199_v5 {
	public int getNum(int[] arr,int aim){
        if(arr==null||arr.length==0||aim<0)
            return 0;
        int[] dp=new int[aim+1];
        for(int i=0;i*arr[0]<=aim;i++)
            dp[i*arr[0]]=1;
        for(int i=1;i<arr.length;i++){
            for(int j=1;j<=aim;j++){
                int num=dp[j];
                num=(num+(j-arr[i]>=0?dp[j-arr[i]]:0))%1000000007;
                dp[j]=num;
            }
        }
        return dp[aim];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int aim=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD19_P199_v5 ma=new CD19_P199_v5();
        System.out.print(ma.getNum(arr,aim));
        sc.close();
    }
}
