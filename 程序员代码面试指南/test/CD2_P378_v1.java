package test;

import java.util.Arrays;
import java.util.Scanner;

//该方法会超时：O(N^3*logN)
public class CD2_P378_v1 {
	//判断一数组是否是可整合子数组
	public static boolean isIntegrated(int[] arr,int left,int right){
        int[] newArr=Arrays.copyOfRange(arr,left,right+1); //复制arr[left,right+1),O(N)
        Arrays.sort(newArr); //O(N*logN)
        for(int i=1;i<newArr.length;i++){
            if(newArr[i-1]!=newArr[i]-1)
               return false;
        }
        return true;
    }
    
	//对各子数组分别判断，若其是可整合子数组，则得到其长度
    public static int getLen1(int[] arr){
        if(arr==null||arr.length==0)
            return 0;
        int len=0;
        for(int i=0;i<arr.length;i++){
            for(int j=i;j<arr.length;j++){
                if(isIntegrated(arr,i,j))
                    len=Math.max(len,j-i+1);
            }
        }
        return len;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int len=sc.nextInt();
        int[] arr=new int[len];
        for(int i=0;i<len;i++)
            arr[i]=sc.nextInt();
        int ans=getLen1(arr);
        System.out.println(ans);
        sc.close();
    }
}
