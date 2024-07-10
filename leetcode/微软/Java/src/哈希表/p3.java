package 哈希表;

import java.util.HashMap;

public class p3 {
	/*
	 * 几点和C++代码相比需要注意的点：
	 * 1.需要利用containsKey方法判断key是否存在,若像C++那样写会报空指针错误
	 * 2.m.put(s.charAt(i),m.get(s.charAt(i))+1);一句不能写成
	 * m.put(s.charAt(i),2);可以考虑例子:"tmmzuxt",对t的判断会出错,键值对(t,0),
	 * 本应变为(t,1),却置为了(t,2)
	 * 注意:HashMap中键是互异的,若put的键原来存在,再次put时会将原来的键值对覆盖掉
	 */
	public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> hash = new HashMap<>();
        Integer res = 0;

        for(int i=0,j=0;j<s.length();j++) {
            if(hash.containsKey(s.charAt(j))) {
                hash.put(s.charAt(j),hash.get(s.charAt(j))+1);
                while(hash.get(s.charAt(j))>1) {
                	hash.put(s.charAt(i),hash.get(s.charAt(i))-1);
                	i++;
                }
            } else {
                hash.put(s.charAt(j),1);
            }
            res = Math.max(res,j-i+1);
        }

        return res;
    }
}
