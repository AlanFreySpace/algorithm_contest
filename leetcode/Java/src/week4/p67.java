package week4;

public class p67 {
	public String addBinary(String a, String b) {
        String ans="";
        int t=0,i=a.length()-1,j=b.length()-1;

        for(;i>=0||j>=0||t!=0;i--,j--){
            if(i>=0) t+=(a.charAt(i)-'0');
            if(j>=0) t+=(b.charAt(j)-'0');
            ans=(t%2)+ans;
            t=t/2;
        }

        return ans;
    }
}
