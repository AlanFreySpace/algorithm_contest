package week2;

public class p28 {
	public int strStr(String s, String p) {
        int n=s.length(),m=p.length();
        if(m==0) return 0;
        s=' '+s;
        p=' '+p;
        int[] next=new int[m+1];

        for(int i=2,j=0;i<=m;i++){
            while(j!=0&&p.charAt(i)!=p.charAt(j+1)) j=next[j];
            if(p.charAt(i)==p.charAt(j+1)) j++;
            next[i]=j;
        }

        for(int i=1,j=0;i<=n;i++){
            while(j!=0&&s.charAt(i)!=p.charAt(j+1)) j=next[j];
            if(s.charAt(i)==p.charAt(j+1)) j++;
            if(j==m) return i-m;
        }

        return -1;
    }
}
