package week1;

public class p7 {
	public int reverse(int x) {
        int r=0;
        while(x!=0){
            if(x>0&&r>(Integer.MAX_VALUE-x%10)/10) return 0;
            if(x<0&&r<(Integer.MIN_VALUE-x%10)/10) return 0;
            r=r*10+x%10;
            x/=10;
        }
        return r;
    }
}
