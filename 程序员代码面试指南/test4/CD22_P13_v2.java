package test4;

import java.util.Scanner;
import java.util.Stack;

/*
 * 利用栈解决该问题。
 * flag:L->M 1 M->L 2 M->R 3 R->M 4
 */
public class CD22_P13_v2 {
	public int hanoi2(int num){
        Stack<Integer> LS=new Stack<Integer>();
        Stack<Integer> MS=new Stack<Integer>();
        Stack<Integer> RS=new Stack<Integer>();
        LS.push(Integer.MAX_VALUE);//注意这种先在栈底压入最大值的技巧
        MS.push(Integer.MAX_VALUE);
        RS.push(Integer.MAX_VALUE);
        for(int i=num;i>0;i--)
            LS.push(i);
        MS.push(LS.pop());
        System.out.println("Move 1 from left to mid");
        int flag=1,res=1;
        while(RS.size()!=num+1){
            if(flag==1||flag==2){
                if(MS.peek()<RS.peek()){
                    res++;
                    System.out.println("Move "+MS.peek()+" from mid to right");
                    RS.push(MS.pop());
                    flag=3;
                }
                else if(MS.peek()>RS.peek()){
                    res++;
                    System.out.println("Move "+RS.peek()+" from right to mid");
                    MS.push(RS.pop());
                    flag=4;
                }
            }
            else{
                if(LS.peek()<MS.peek()){
                    res++;
                    System.out.println("Move "+LS.peek()+" from left to mid");
                    MS.push(LS.pop());
                    flag=1;
                }
                else if(LS.peek()>MS.peek()){
                    res++;
                    System.out.println("Move "+MS.peek()+" from mid to left");
                    LS.push(MS.pop());
                    flag=2;
                }
            }
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        CD22_P13_v2 ma=new CD22_P13_v2();
        System.out.print("It will move "+ma.hanoi2(n)+" steps.");
        sc.close();
    }
}
