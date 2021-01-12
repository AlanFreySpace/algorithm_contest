package test;

import java.util.Scanner;
import java.util.Stack;

public class CD6_P5_v1 {
	public static void main(String[] args){
        twoStackQueue queue=new twoStackQueue();
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        for(int i=0;i<N;i++){
            String temp=sc.next();
            if("add".equals(temp))
                queue.add(sc.nextInt());
            else if("peek".equals(temp))
                System.out.println(queue.peek());
            else
                queue.poll();
        }
        sc.close();
    }
}

class twoStackQueue{
    private Stack<Integer> stackPush;
    private Stack<Integer> stackPop;
    
    public twoStackQueue(){
        stackPush=new Stack<Integer>();
        stackPop=new Stack<Integer>();
    }
    
    /*
     * �Թؼ���������֣�popջΪ��ʱ�ſ�ѹ�����У�
     * ����һ��popջ��ѹ�룬Ҫ��pushջ������Ԫ�ض�
     * һ����ѹ��popջ�С�
     */
    public void pushToPop(){
        if(stackPop.isEmpty())
            while(!stackPush.isEmpty())
                stackPop.push(stackPush.pop());
    }
    
    //ÿ��add,poll,peekʱ��Ҫ����Ƿ���Խ���pushToPop
    public void add(int num){
        stackPush.push(num);
        pushToPop();
    }
    
    public int poll(){
        if(stackPush.isEmpty()&&stackPop.isEmpty())
            throw new RuntimeException("Your queue is empty");
        pushToPop();
        return stackPop.pop();
    }
    
    public int peek(){
        if(stackPush.isEmpty()&&stackPop.isEmpty())
            throw new RuntimeException("Your queue is empty");
        pushToPop();
        return stackPop.peek();
    }
}
