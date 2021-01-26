package test3;
import java.util.*;

public class _1CD101_P20_v1 {
	/*
	 * 时间复杂度为O(N^2)的解法，很容易，
	 * 只需每个位置分别向左和向右遍历一下。
	 */
	public int[][] getPosi(int[] arr){
        int[][] res=new int[arr.length][2];
        for(int i=0;i<arr.length;i++){
            int leftIndex=-1,rightIndex=-1,cur=i-1;
            while(cur>=0){
                if(arr[cur]<arr[i]){
                    leftIndex=cur;
                    break;
                }
                cur--;
            }
            cur=i+1;
            while(cur<arr.length){
                if(arr[cur]<arr[i]){
                    rightIndex=cur;
                    break;
                }
                cur++;
            }
            res[i][0]=leftIndex;
            res[i][1]=rightIndex;
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        _1CD101_P20_v1 ma=new _1CD101_P20_v1();
        int[][] res=ma.getPosi(arr);
        for(int i=0;i<n;i++)
            System.out.println(res[i][0]+" "+res[i][1]);
        sc.close();
    }
}
