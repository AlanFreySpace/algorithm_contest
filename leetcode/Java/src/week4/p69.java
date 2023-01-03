package week4;

public class p69 {
	/**
	 * 需要注意的几点:
	 * 1.二分法:注意mid=(l+r+1)>>1,不能写成mid=(l+r)>>1,否则会死循环
	 * 2.由于int除法向下取整的特性,因此:
	 * 1)若mid*mid<x,因为mid是正整数,因此有mid<=x/mid;
	 * 2)若mid*mid=x,有mid=x/mid;
	 * 3)若mid*mid>x,因为mid是正整数,因此有mid>x/mid;
	 */
	public int mySqrt(int x) {
        long l=0,r=x;
        while(l<r){
            long mid=(l+r+1)>>1;
            if(mid<=x/mid) l=mid;
            else r=mid-1;
        }
        return (int)l;
    }
}
