package week2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class p30 {
	public List<Integer> findSubstring(String s, String[] words) {
        int n=s.length(),m=words.length,w=words[0].length();
        HashMap<String,Integer> rec=new HashMap<>();
        for(int i=0;i<m;i++){
            if(!rec.containsKey(words[i])) rec.put(words[i],1);
            else rec.put(words[i],rec.get(words[i])+1);
        }

        List<Integer> res=new ArrayList<>();
        for(int i=0;i<w;i++){
            int cnt=0;
            HashMap<String,Integer> wd=new HashMap<>();
            for(int j=i;j<=n-w;j+=w){
                if(j>=m*w){
                    String str1=s.substring(j-m*w,j-m*w+w);
                    wd.put(str1,wd.get(str1)-1);
                    if(rec.containsKey(str1)){
                        if(wd.get(str1)<rec.get(str1)) cnt--;
                    }
                }
                String str2=s.substring(j,j+w);
                if(!wd.containsKey(str2)) wd.put(str2,1);
                else wd.put(str2,wd.get(str2)+1);
                if(rec.containsKey(str2)){
                    if(wd.get(str2)<=rec.get(str2)) cnt++;
                }
                if(cnt==m) res.add(j-m*w+w);
            }
        }

        return res;
    }
}
