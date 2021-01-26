package test3;

import java.util.Scanner;

/*
 * 这种方法虽然名义上复杂度为O(N^2)(就是101题v1的做法)，
 * 但因为可以以一个字符串的形式输出，实际运行时间反而少
 */
public class _2CD188_P20_v2 {
	public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        StringBuilder sb=new StringBuilder();
         
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
            sb.append(leftIndex).append(" ").append(rightIndex).append("\n");
        }
         
        System.out.print(sb.toString());
        sc.close();
    }
}
