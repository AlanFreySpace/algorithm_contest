package test;

import java.util.Scanner;
import java.util.Stack;

public class CD5_P1_v1 {
	/*���õ�һ����Ʒ������˷���stackMinѹ��
	 * ʱ��ʡ�ռ䣬���ǵ���ʱ�Է�ʱ�䡣
	 * ʱ�临�Ӷ�O(1),�ռ临�Ӷ�O(n)
	 */
	public static void main(String[] args){
        myStack stack=new myStack();
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        for(int i=0;i<N;i++){
            String temp=sc.next();
            //ע���ж��ַ���ʱҪ��equals��������жϵ�ַ
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
    	//���û�����Ķ�·ЧӦ
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
