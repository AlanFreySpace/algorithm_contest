package week2;

import java.util.ArrayList;
import java.util.List;

public class p22 {
	List<String> ans=new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        dfs(n,0,0,"");
        return ans;
    }

    void dfs(int n,int l,int r,String s){
        if(l==n&&r==n) ans.add(s);
        if(l<n) dfs(n,l+1,r,s+'(');//此位置添加添加左括号
        if(r<n&&l>r) dfs(n,l,r+1,s+')');//此位置添加右括号
    }
}
