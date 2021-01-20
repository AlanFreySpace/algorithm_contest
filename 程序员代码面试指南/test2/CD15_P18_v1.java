package test2;

import java.util.LinkedList;
import java.util.Scanner;

public class CD15_P18_v1 {
	public int[] getMaxWindow(int[] arr,int w){
		/*
		 * qmax是辅助双端队列，存放数组元素的下标，
		 * 队首对应元素的值大，队尾小
		 * 由放入规则，qmax中下标元素是单调递增的
		 */
        LinkedList<Integer> qmax=new LinkedList<Integer>();
        int[] res=new int[arr.length-w+1];
        int index=0;
        for(int i=0;i<arr.length;i++){
            while(!qmax.isEmpty()&&arr[i]>=arr[qmax.peekLast()])
                qmax.pollLast();
            qmax.addLast(i);
            if(qmax.peekFirst()==i-w)
                qmax.pollFirst();
            if(i>=w-1)
                res[index++]=qmax.peekFirst();
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int w=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD15_P18_v1 ma=new CD15_P18_v1();
        int[] res=ma.getMaxWindow(arr,w);
        for(int i=0;i<n-w+1;i++)
            System.out.print(arr[res[i]]+" ");
        sc.close();
    }
}
