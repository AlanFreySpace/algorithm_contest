package week3;

public class p38 {
	public String countAndSay(int n) {
        String ans="1";
        /*
         * Java中int和String相互转换
         * https://www.runoob.com/w3cnote/java-string-and-int-convert.html
         */
        for(int i=0;i<n-1;i++){
            String tmp="";
            for(int j=0;j<ans.length();){
                int k=j+1;
                while(k<ans.length()&&ans.charAt(k)==ans.charAt(j)) k++;
                tmp+=String.valueOf(k-j)+ans.charAt(j);
                j=k;
            }
            ans=tmp;
        }

        return ans;
    }
}
