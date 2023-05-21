package week6;

public class p96_2 {
	/**
	 * dp[i]:数字[1,i]构成的二叉树数量
	 * dp[j]:以数字j+1作为根节点,则左侧二叉树的数量为dp[j]
	 * dp[i-j-1]:以数字j+1作为根节点,则右侧二叉树的数量为dp[i-j-1]
	 */
	public int numTrees(int n) {
        int[] dp=new int[n+1];
        dp[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }

        return dp[n];
    }
}
