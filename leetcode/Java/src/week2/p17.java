package week2;

import java.util.ArrayList;
import java.util.List;

public class p17 {
	List<String> ans=new ArrayList<>();
    String[] strs={
        "","","abc","def",
        "ghi","jkl","mno",
        "pqrs","tuv","wxyz"
    };

    public List<String> letterCombinations(String digits) {
        if(digits.length()==0) return ans;
        dfs(digits,0,"");
        return ans;
    }

    void dfs(String digits,int i,String s){
        if(i==digits.length()){
            ans.add(s);
            return;
        }
        int index=digits.charAt(i)-'0';
        for(int j=0;j<strs[index].length();j++)
            dfs(digits,i+1,s+strs[index].charAt(j));
    }
}
