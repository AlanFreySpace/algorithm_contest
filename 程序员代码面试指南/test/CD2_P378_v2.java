package test;

import java.util.HashSet;
import java.util.Scanner;

//时间复杂度符合要求，为O(N^2)
public class CD2_P378_v2 {
	public static int getLen2(int[] arr){
        if(arr==null||arr.length==0)
            return 0;
        int max=0;
        int min=0;
        int len=0;
        //利用HashSet判断是否有重复元素
        HashSet<Integer> set=new HashSet<Integer>();
        for(int i=0;i<arr.length;i++){
            max=Integer.MIN_VALUE;
            min=Integer.MAX_VALUE;
            for(int j=i;j<arr.length;j++){
            	/*break作用:终止所在层的循环
            	 * break语句对if-else的条件语句不起作用。
            	 * 在多层循环中，一个break语句只向外跳一层。
                */
                if(set.contains(arr[j]))//O(1)
                    break;
                set.add(arr[j]);
                max=Math.max(max,arr[j]);
                min=Math.min(min,arr[j]);
                if(max-min==j-i)//O(1),新的判断可整合子数组的方式
                    len=Math.max(len,j-i+1);
            }
            set.clear();
        }
        return len;
    }
    
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int len=sc.nextInt();
        int[] arr=new int[len];
        for(int i=0;i<len;i++)
            arr[i]=sc.nextInt();
        int ans=getLen2(arr);
        System.out.println(ans);
        sc.close();
    }
}
