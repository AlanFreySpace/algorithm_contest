package week2;

public class p14 {
	public String longestCommonPrefix(String[] strs) {
        String res="";

        for(int i=0;i<strs[0].length();i++){
            char tmp=strs[0].charAt(i);
            for(int j=1;j<strs.length;j++){
                if(i==strs[j].length()||tmp!=strs[j].charAt(i))
                    return res;
            }
            res+=tmp;
        }

        return res;
    }
}
