package week1;

public class p5 {
	public String longestPalindrome(String s) {
        int len=s.length();
        String res="";
        for(int i=0;i<len;i++){
            int l=i-1,r=i+1;
            while(l>=0&&r<s.length()&&s.charAt(l)==s.charAt(r)){
                l--;
                r++;
            }
            //注意一下substring的用法
            if(res.length()<r-l-1) res=s.substring(l+1,r);

            l=i;
            r=i+1;
            while(l>=0&&r<s.length()&&s.charAt(l)==s.charAt(r)){
                l--;
                r++;
            }
            if(res.length()<r-l-1) res=s.substring(l+1,r);
        }
        return res;
    }
}
