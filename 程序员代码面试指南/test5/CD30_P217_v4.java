package test5;

import java.util.Scanner;

public class CD30_P217_v4 {
	public int process(int[] arr){
        int from=1,mid=2,to=3,tmp=0,res=0;
        int[] count=new int[arr.length];
        count[0]=1;
        for(int i=1;i<arr.length;i++)
            count[i]=(count[i-1]<<1)%(1000000007);
        for(int i=arr.length-1;i>=0;i--){
            if(arr[i]==mid)
                return -1;
            if(arr[i]==from){
                tmp=to;
                to=mid;
            }else{
                res=(res+count[i])%1000000007;
                tmp=from;
                from=mid;
            }
            mid=tmp;
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD30_P217_v4 ma=new CD30_P217_v4();
        System.out.print(ma.process(arr));
        sc.close();
    }
}
