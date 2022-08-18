package week2;

public class p11 {
	/*
	 * 其实是一种排除的思想:当h[i]<h[j]时,如果令j--,那么装的水只会更少,因此
	 * 只能i++才有可能装的水更多,依此类推
	 */
	public int maxArea(int[] h) {
        int res=0;
        for(int i=0,j=h.length-1;i<j;){
            res=Math.max(res,Math.min(h[i],h[j])*(j-i));
            if(h[i]<h[j]) i++;
            else j--;
        }
        return res;
    }
}
