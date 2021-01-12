package test;

import java.util.Scanner;
import java.util.Stack;

public class CD7_P7_v1 {
	//�õ�ջ�����һ��Ԫ�أ��������Ƴ�ջ
	public int getAndRemoveLastElement(Stack<Integer> stack){
        int result=stack.pop();
        if(stack.isEmpty())//�ݹ��
            return result;
        int last=getAndRemoveLastElement(stack);
        stack.push(result);
        return last;
    }
    
	//����getAndRemoveLastElement��������ջ��Ԫ��
    public void reverse(Stack<Integer> stack){
        if(stack.isEmpty())
            return;
        int last=getAndRemoveLastElement(stack);
        reverse(stack);
        stack.push(last);
    }
    
    public static void main(String[] args){
        Stack<Integer> stack=new Stack<Integer>();
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] num=new int[N];
        for(int i=0;i<N;i++)
            num[N-i-1]=sc.nextInt();
        for(int i=0;i<N;i++)
            stack.push(num[i]);
        CD7_P7_v1 ma=new CD7_P7_v1();
        ma.reverse(stack);
        for(int i=0;i<N;i++)
            System.out.print(stack.pop()+" ");
        sc.close();
    }
}
