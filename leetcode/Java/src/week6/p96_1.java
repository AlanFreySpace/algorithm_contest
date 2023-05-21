package week6;

public class p96_1 {
	public int numTrees(int n) {
        long ans=1;//注意这里用long
        for(int i=2;i<=n;i++){
            ans=2*(2*i-1)*ans/(i+1);//避免计算过程中溢出
        }
        return (int)ans;
    }
}
