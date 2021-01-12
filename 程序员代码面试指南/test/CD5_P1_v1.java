package test;

import java.util.Scanner;
import java.util.Stack;

public class CD5_P1_v1 {
	/*采用第一种设计方案，此方案stackMin压入
	 * 时稍省空间，但是弹出时稍费时间。
	 * 时间复杂度O(1),空间复杂度O(n)
	 */
	public static void main(String[] args){
        myStack stack=new myStack();
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        for(int i=0;i<N;i++){
            String temp=sc.next();
            //注意判断字符串时要用equals，否则会判断地址
            if("push".equals(temp)){
                int temp1=sc.nextInt();
                stack.push(temp1);
            }
            else if("getMin".equals(temp)){
                int a=stack.getMin();
                System.out.println(a);
            }
            else
                stack.pop();
        }
        sc.close();
    }
}

class myStack{
    Stack<Integer> stackData;
    Stack<Integer> stackMin;
    
    public myStack(){
        this.stackData=new Stack<Integer>();
        this.stackMin=new Stack<Integer>();
    }
    
    public void push(int num){
    	//利用或运算的短路效应
        if(this.stackMin.isEmpty()||this.stackMin.peek()>=num)
            this.stackMin.push(num);
        this.stackData.push(num);
    }
    
    public int pop(){
        if(this.stackMin.isEmpty())
            throw new RuntimeException("Your stack is empty");
        int value=this.stackData.pop();
        if(value==this.stackMin.peek())
            this.stackMin.pop();
        return value;
    }
    
    public int getMin(){
        if(this.stackMin.isEmpty())
            throw new RuntimeException("Your stack is empty");
        return this.stackMin.peek();
    }
}
