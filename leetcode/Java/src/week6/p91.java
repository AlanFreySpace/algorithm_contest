package week6;

public class p91 {
	public int numDecodings(String s) {
        int n=s.length();
        int[] f=new int[n];

        if(s.charAt(0)!='0') f[0]=1;
        if(n>=2){
            char tmp1=s.charAt(0),tmp2=s.charAt(1);
            if(tmp1!='0'){
                if(tmp2!='0') f[1]++;
                if((tmp1-'0')*10+(tmp2-'0')<27) f[1]++;
            }
        }

        for(int i=2;i<n;i++){
            char tmp1=s.charAt(i-1),tmp2=s.charAt(i);
            if(tmp2!='0') f[i]+=f[i-1];
            if(tmp1!='0'&&(tmp1-'0')*10+(tmp2-'0')<27) f[i]+=f[i-2];
        }

        return f[n-1];
    }
}
