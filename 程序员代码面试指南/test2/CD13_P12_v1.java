package test2;

import java.util.Scanner;
import java.util.Stack;

//利用两个栈实现栈的排序
public class CD13_P12_v1 {
	public void sortStackByStack(Stack<Integer> stack){
        Stack<Integer> help=new Stack<Integer>();
        while(!stack.isEmpty()){
            int cur=stack.pop();
            while(!help.isEmpty()&&cur>help.peek())
                stack.push(help.pop());
            help.push(cur);
        }
        
        while(!help.empty())
            stack.push(help.pop());
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=N-1;i>=0;i--)
            arr[i]=sc.nextInt();
        Stack<Integer> stack=new Stack<Integer>();
        for(int i=0;i<N;i++)
            stack.push(arr[i]);
        CD13_P12_v1 ma=new CD13_P12_v1();
        ma.sortStackByStack(stack);
        for(int i=0;i<N;i++)
            System.out.print(stack.pop()+" ");
        sc.close();
    }
}
