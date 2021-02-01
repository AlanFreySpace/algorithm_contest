package test5;

import java.util.Scanner;

/*
 * 这段程序逻辑正确，但却无法通过测评，因为1<<i会溢出，
 * 没有达到取余的效果。可以通过测评的见v4，引入count数组
 * 即可，从而达到取余效果。
 */
public class CD30_P217_v3 {
	public int process(int[] arr){
        int from=1,mid=2,to=3,tmp=0,res=0,tmp1=0;
        for(int i=arr.length-1;i>=0;i--){
            if(arr[i]==mid)
                return -1;
            if(arr[i]==from){
                tmp=to;
                to=mid;
            }else{
                tmp1=(1<<i)%1000000007;
                res=res+tmp1;
                res%=1000000007;
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
        CD30_P217_v3 ma=new CD30_P217_v3();
        System.out.print(ma.process(arr));
        sc.close();
    }
}
