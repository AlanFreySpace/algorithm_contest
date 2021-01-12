package test;

import java.util.Scanner;
import java.util.Stack;

public class CD5_P1_v2 {
	/*
	 * 利用方案二
	 * */
	public static void main(String[] args){
        myStack1 stack=new myStack1();
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        for(int i=0;i<N;i++){
            String temp=sc.next();
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

class myStack1{
    Stack<Integer> stackData;
    Stack<Integer> stackMin;
    
    public myStack1(){
        this.stackData=new Stack<Integer>();
        this.stackMin=new Stack<Integer>();
    }
    
    public void push(int num){
        if(this.stackMin.isEmpty()||this.stackMin.peek()>=num)
            this.stackMin.push(num);
        else
            this.stackMin.push(this.stackMin.peek());
        this.stackData.push(num);
    }
    
    public int pop(){
        if(this.stackMin.isEmpty())
            throw new RuntimeException("Your stack is empty");
        this.stackMin.pop();
        return this.stackData.pop();
    }
    
    public int getMin(){
        if(this.stackMin.isEmpty())
            throw new RuntimeException("Your stack is empty");
        return this.stackMin.peek();
    }
}
