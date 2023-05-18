package week6;

import java.util.ArrayList;
import java.util.List;

public class p93 {
	String path="";
    List<String> ans=new ArrayList<>();

    public List<String> restoreIpAddresses(String s) {
        dfs(s,1,0);
        return ans;
    }

    void dfs(String s,int round,int begin){
        if(begin==s.length()){
            if(round==5) ans.add(path);
            return;
        }

        for(int i=begin;i<s.length()&&i-begin<3;i++){
            String tmp=s.substring(begin,i+1),origi_path=path;
            if(i-begin==0){
                path+=tmp;
                if(round<4) path+=".";
                dfs(s,round+1,i+1);
            }
            else{
                if(tmp.charAt(0)!='0'&&Integer.valueOf(tmp)<=255){
                    path+=tmp;
                    if(round<4) path+=".";
                    dfs(s,round+1,i+1);
                }
            }
            path=origi_path;//恢复现场
        }
    }
}
