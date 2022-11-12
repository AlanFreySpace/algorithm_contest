package week3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

//Java本题涉及的容器和语法比较麻烦,应注意学习
public class p49 {
	public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,List<String>> hashmap=new HashMap<>();
        List<List<String>> ans=new ArrayList<>();

        for(int i=0;i<strs.length;i++){
            String tmp=strs[i];
            char[] tmpChar=tmp.toCharArray();
            Arrays.sort(tmpChar);
            tmp=new String(tmpChar);
            if(hashmap.containsKey(tmp)){
                hashmap.get(tmp).add(strs[i]);
            }else{
                List<String> list=new ArrayList<>();
                list.add(strs[i]);
                hashmap.put(tmp,list);
            }
        }

        for(String s:hashmap.keySet()){
            ans.add(hashmap.get(s));
        }

        return ans;
    }
}
