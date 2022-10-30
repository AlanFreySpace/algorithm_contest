package week3;

import java.util.Stack;

public class p32 {
	public int longestValidParentheses(String s) {
        Stack<Integer> sk=new Stack<>();
        int res=0;

        for(int i=0,start=-1;i<s.length();i++){
            if(s.charAt(i)=='(') sk.push(i);
            else{
                if(!sk.empty()){//右括号可以被匹配
                    sk.pop();
                    if(!sk.empty()) res=Math.max(res,i-sk.peek());//左括号多
                    else res=Math.max(res,i-start);//左括号数量正好
                }
                else start=i;//右括号多，则应更新合法序列的起点
            }
        }

        return res;
    }
}
