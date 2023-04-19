package week5;

import java.util.HashMap;

public class p76 {
	public String minWindow(String s, String t) {
        String ans="";
        HashMap<Character,Integer> hs=new HashMap<>(),ht=new HashMap<>();

        for(int i=0;i<t.length();i++){//获取t中各字符出现的次数
            char tmp=t.charAt(i);
            if(!ht.containsKey(tmp)){
                ht.put(tmp,1);
            }
            else{
                ht.put(tmp,ht.get(tmp)+1);
            }
        }

        int cnt=0;//有效字符数
        for(int i=0,j=0;i<s.length();i++){
        	/**
        	 * 窗口先扩张，直到有效字符数满足要求
        	 */
            char tmp=s.charAt(i);
            if(!hs.containsKey(tmp)){
                hs.put(tmp,1);
            }
            else{
                hs.put(tmp,hs.get(tmp)+1);
            }

            if(ht.containsKey(tmp)&&hs.get(tmp)<=ht.get(tmp)){
                cnt++;
            }

            /**
             * 当窗口中有效字符数满足要求后，再去掉窗口头部的无用字符，以最小化字符串长度
             */
            char tmp2=s.charAt(j);
            if(cnt==t.length()){
                while(!ht.containsKey(tmp2)||ht.get(tmp2)<hs.get(tmp2)){
                    hs.put(tmp2,hs.get(tmp2)-1);
                    tmp2=s.charAt(++j);
                }
                String comp=s.substring(j,i+1);
                if("".equals(ans)||comp.length()<ans.length()){
                    ans=comp;
                }
            }
        }

        return ans;
    }
}
