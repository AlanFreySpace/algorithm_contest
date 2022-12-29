package week4;

public class p66 {
	public int[] plusOne(int[] digits) {
        int n=digits.length;

        int to=1;//进位
        for(int i=n-1;i>=0;i--){
            digits[i]+=to;
            to=digits[i]/10;
            digits[i]=digits[i]%10;
        }
        if(to==1){//只需注意处理这种特殊的情况
            digits=new int[n+1];
            digits[0]=1;
        }
        return digits;
    }
}
