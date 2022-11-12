package week3;

public class p50 {
	public double myPow(double x, int n) {
        double ans=1;
        int k=Math.abs(n);
        double cal=x;

        while(k!=0){
        	//注意使用位运算获取数某位是否为1,这种方法很巧妙
            if((k&1)==1) ans*=cal;
            cal*=cal;
            k/=2;
        }

        if(n<0) ans=1/ans;
        return ans;
    }
}
