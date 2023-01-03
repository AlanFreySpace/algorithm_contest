package week5;

import java.util.Stack;

public class p71 {
	//方法1:和C++解法的思路是相同的
	public String simplifyPath(String path) {
        int len=path.length();
        if(path.charAt(len-1)!='/') path+='/';
        String tmp="",ans="";
        Stack<String> stk=new Stack<>();

        len=path.length();
        for(int i=1;i<len;i++){
            char c=path.charAt(i);
            if(c=='/'){
                if(tmp.length()!=0){
                    if(tmp.equals("..")){
                        if(!stk.empty()) stk.pop();
                    }
                    else if(!tmp.equals(".")) stk.push('/'+tmp);
                }
                tmp="";
            }else tmp+=c;
        }

        for(String s:stk) ans+=s;
        if(ans.length()==0) ans="/";
        return ans;
    }
}
