package week1;

import java.util.HashMap;

public class p3 {
	/*
	 * 几点和C++代码相比需要注意的点：
	 * 1.需要利用containsKey方法判断key是否存在,若像C++那样写会报空指针错误
	 * 2.m.put(s.charAt(i),m.get(s.charAt(i))+1);一句不能写成
	 * m.put(s.charAt(i),2);可以考虑例子:"tmmzuxt",对t的判断会出错,键值对(t,0),
	 * 本应变为(t,1),却置为了(t,2)
	 */
	public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> m=new HashMap<>();
        int res=0;
        for(int j=0,i=0;i<s.length();i++){
            if(m.containsKey(s.charAt(i))){
                m.put(s.charAt(i),m.get(s.charAt(i))+1);
                while(m.get(s.charAt(i))>1) m.put(s.charAt(j),m.get(s.charAt(j++))-1);
            }else m.put(s.charAt(i),1);
            if(i-j+1>res) res=i-j+1;
        }
        return res;
    }
}
