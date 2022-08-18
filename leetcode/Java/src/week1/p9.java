package week1;

public class p9 {
	public boolean isPalindrome(int x) {
        if(x<0) return false;
        int y=x;
        long res=0;
        while(x!=0){
            res=res*10+x%10;
            x/=10;
        }
        return res==y;
    }
}
