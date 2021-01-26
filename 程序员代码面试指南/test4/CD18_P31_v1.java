package test4;

import java.util.LinkedList;
import java.util.Scanner;

/*
 * 利用两个观察到的性质+双端队列的解法，复杂度为O(N)
 */
public class CD18_P31_v1 {
	public int getNum(int[] arr,int num){
        LinkedList<Integer> qmax=new LinkedList<Integer>();
        LinkedList<Integer> qmin=new LinkedList<Integer>();
        int i=0,j=0,res=0;
        while(i<arr.length){
            while(j<arr.length){
                while(!qmin.isEmpty()&&arr[qmin.peekLast()]>=arr[j])
                    qmin.pollLast();
                qmin.addLast(j);
                while(!qmax.isEmpty()&&arr[qmax.peekLast()]<=arr[j])
                    qmax.pollLast();
                qmax.addLast(j);
                
                if(arr[qmax.getFirst()]-arr[qmin.getFirst()]>num)
                    break;
                j++;
            }
            res+=j-i;
            
            if(qmin.peekFirst()==i)
                qmin.pollFirst();
            if(qmax.peekFirst()==i)
                qmax.pollFirst();
            i++;
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int num=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD18_P31_v1 ma=new CD18_P31_v1();
        System.out.print(ma.getNum(arr,num));
        sc.close();
    }
}
