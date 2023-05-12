package week5;

import java.util.Arrays;

public class p87_1 {
	// 复杂度高的递归方法，会超时
	public boolean isScramble(String s1, String s2) {
        if(s1.equals(s2)) return true;
        String ss1=sort(s1),ss2=sort(s2);
        if(!ss1.equals(ss2)) return false;

        int n=s1.length();
        for(int i=1;i<n;i++){
            if(isScramble(s1.substring(0,i),s2.substring(0,i))&&
               isScramble(s1.substring(i,n),s2.substring(i,n))){
                return true;
            }

            if(isScramble(s1.substring(0,i),s2.substring(n-i,n))&&
               isScramble(s1.substring(i,n),s2.substring(0,n-i))){
                return true;
            }
        }

        return false;
    }

    String sort(String s){
        char[] chars=s.toCharArray();
        Arrays.sort(chars);
        s=new String(chars);
        return s;
    }
}
