package week1;

import java.util.HashMap;

public class p3 {
	/*
	 * �����C++���������Ҫע��ĵ㣺
	 * 1.��Ҫ����containsKey�����ж�key�Ƿ����,����C++����д�ᱨ��ָ�����
	 * 2.m.put(s.charAt(i),m.get(s.charAt(i))+1);һ�䲻��д��
	 * m.put(s.charAt(i),2);���Կ�������:"tmmzuxt",��t���жϻ����,��ֵ��(t,0),
	 * ��Ӧ��Ϊ(t,1),ȴ��Ϊ��(t,2)
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
