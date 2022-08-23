package week2;

import java.util.Stack;

public class p20 {
	public boolean isValid(String s) {
        Stack<Character> stk=new Stack<>();

        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(c=='('||c=='{'||c=='[') stk.push(c);
            else{
                if(stk.empty()) return false;
                if(c==')'&&stk.peek()!='(') return false;
                if(c=='}'&&stk.peek()!='{') return false;
                if(c==']'&&stk.peek()!='[') return false;
                else stk.pop();
            }
        }

        return stk.empty();
    }
}
