package week3;

public class p43 {
	public String multiply(String num1, String num2) {
        int n=num1.length(),m=num2.length();
        int[] a=new int[n],b=new int[m],res=new int[n+m];
        String ans="";

        for(int i=0;i<n;i++) a[n-i-1]=num1.charAt(i)-'0';
        for(int i=0;i<m;i++) b[m-i-1]=num2.charAt(i)-'0';

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                res[i+j]+=a[i]*b[j];
        
        for(int i=0,t=0;i<res.length;i++){
            res[i]+=t;
            t=res[i]/10;
            res[i]%=10;
        }

        int k=res.length-1;
        while(k>0&&res[k]==0) k--;
        for(int i=k;i>=0;i--) ans+=res[i];
        return ans;
    }
}
