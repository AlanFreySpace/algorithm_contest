package week1;

public class p6 {
	public String convert(String s, int n) {
        if(n==1) return s;
        String res="";
        int len=s.length();
        for(int i=0;i<n;i++){
            if(i==0||i==n-1){
                for(int j=i;j<len;j+=(2*n-2)) res+=s.charAt(j);
            }else{
                for(int j=i,k=2*n-j-2;j<len;j+=(2*n-2),k+=(2*n-2)){
                    res+=s.charAt(j);
                    if(k<len) res+=s.charAt(k);
                }
            }
        }
        return res;
    }
}
