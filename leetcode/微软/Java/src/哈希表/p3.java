package ��ϣ��;

import java.util.HashMap;

public class p3 {
	/*
	 * �����C++���������Ҫע��ĵ㣺
	 * 1.��Ҫ����containsKey�����ж�key�Ƿ����,����C++����д�ᱨ��ָ�����
	 * 2.m.put(s.charAt(i),m.get(s.charAt(i))+1);һ�䲻��д��
	 * m.put(s.charAt(i),2);���Կ�������:"tmmzuxt",��t���жϻ����,��ֵ��(t,0),
	 * ��Ӧ��Ϊ(t,1),ȴ��Ϊ��(t,2)
	 * ע��:HashMap�м��ǻ����,��put�ļ�ԭ������,�ٴ�putʱ�Ὣԭ���ļ�ֵ�Ը��ǵ�
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
