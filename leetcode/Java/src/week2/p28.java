package week2;

public class p28 {
	/*
	 * next[i]表示p[1..i]中自匹配的最大真前缀、真后缀的长度
	 */
	public int strStr(String s, String p) {
        int n=s.length(),m=p.length();
        if(m==0) return 0;
        s=' '+s;
        p=' '+p;
        int[] next=new int[m+1];

        for(int i=2,j=0;i<=m;i++){
        	/*
        	 * j是p[1..i-1]中自匹配的真前缀、真后缀的长度
        	 * 尝试寻找p[1..i-1]的一个真前缀、真后缀，使得p[i]==p[j+1]以计算next[i]
        	 */
            while(j!=0&&p.charAt(i)!=p.charAt(j+1)) j=next[j];
            if(p.charAt(i)==p.charAt(j+1)) j++;
            next[i]=j;
        }

        for(int i=1,j=0;i<=n;i++){
        	/*
        	 * p[j]和s[i-1]已经对齐匹配 尝试扩大对齐
        	 * 策略:不断尝试可能的j,使得p[j]和s[i-1]对齐,比较p[j+1]和s[i]以扩大对齐
        	 */
            while(j!=0&&s.charAt(i)!=p.charAt(j+1)) j=next[j];
            if(s.charAt(i)==p.charAt(j+1)) j++;
            if(j==m) return i-m;
        }

        return -1;
    }
}
