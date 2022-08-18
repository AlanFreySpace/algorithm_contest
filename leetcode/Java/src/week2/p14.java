package week2;

public class p14 {
	public String longestCommonPrefix(String[] strs) {
        String res="";

        for(int i=0;i<strs[0].length();i++){
            char tmp=strs[0].charAt(i);
            for(String s:strs){
                if(i==s.length()||tmp!=s.charAt(i))
                    return res;
            }
            res+=tmp;
        }

        return res;
    }
}
