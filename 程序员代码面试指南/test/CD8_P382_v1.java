package test;

import java.util.Scanner;

public class CD8_P382_v1 {
	public int getMaxLength(int[] arr,int k){
        if(arr==null||arr.length==0||k<=0)
            return 0;
        int left=0,right=0,sum=arr[0],len=0;
        //注意此处应判断left<=right
        while(right<arr.length&&left<=right){
            if(sum==k){
                len=Math.max(len,right-left+1);
                sum-=arr[left++];
            }
            else if(sum<k){
                right++;
                //注意right可能越界，下面left同理
                if(right==arr.length)
                    break;
                sum+=arr[right];
            }
            else{
            	//注意顺序，应该先减arr[left],再left++
                sum-=arr[left];
                left++;
                if(left==arr.length)
                    break;
            }
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
        CD8_P382_v1 ma=new CD8_P382_v1();
        System.out.println(ma.getMaxLength(arr,k));
        sc.close();
    }
}
