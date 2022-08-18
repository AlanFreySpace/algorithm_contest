package week1;

public class p8 {
	public int myAtoi(String s) {
        int k=0,len=s.length();
        for(int i=0;i<len&&s.charAt(i)==' ';i++) k++;
        if(k==len) return 0;

        int minus=1;
        if(s.charAt(k)=='-'){
            minus=-1;
            k++;
        }
        else if(s.charAt(k)=='+') k++;

        int r=0;
        while(k<len&&s.charAt(k)>='0'&&s.charAt(k)<='9'){
            int x=s.charAt(k)-'0';
            if(minus==1&&r>(Integer.MAX_VALUE-x)/10) return Integer.MAX_VALUE;
            if(minus==-1&&-r<(Integer.MIN_VALUE+x)/10) return Integer.MIN_VALUE;
            if(minus==-1&&-r*10-x==Integer.MIN_VALUE) return Integer.MIN_VALUE;
            r=r*10+x;
            k++;
        }

        if(minus==-1) r=-r;
        return r;
    }
}
