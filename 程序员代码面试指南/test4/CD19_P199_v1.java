package test4;

import java.util.Scanner;

/*
 * 暴力递归方法，复杂度过高，可达O(aim^N)
 */
public class CD19_P199_v1 {
	public int getNum(int[] arr,int index,int rest){
        int res=0;
        if(arr==null||arr.length==0)
            return 0;
        if(index==arr.length)
            return rest==0?1:0;
        for(int i=0;i*arr[index]<=rest;i++)
            res=(res+getNum(arr,index+1,rest-i*arr[index]))%((int)10E9+7);
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int aim=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD19_P199_v1 ma=new CD19_P199_v1();
        System.out.print(ma.getNum(arr,0,aim));
        sc.close();
    }
}
