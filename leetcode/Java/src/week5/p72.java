package week5;

public class p72 {
	/*
	 * f[i][j]:由word1[0...i]变为word2[0...j]所需的最少步数
	 * 注意动态规划的分类标准:
	 * 最后一个字母word2[j]是通过删除得来的；
	 * 最后一个字母word2[j]是通过插入得来的；
	 * 最后一个字母word2[j]是通过替换得来的；
	 * 最后一个字母word2[j]没有进行以上任何一种操作。
	 */
	public int minDistance(String word1, String word2) {
        word1=" "+word1;
        word2=" "+word2;
        int len1=word1.length(),len2=word2.length();
        int[][] f=new int[len1][len2];

        for(int i=0;i<len2;i++) f[0][i]=i;
        for(int i=0;i<len1;i++) f[i][0]=i;

        for(int i=1;i<len1;i++){
            for(int j=1;j<len2;j++){
                f[i][j]=Math.min(f[i-1][j]+1,f[i][j-1]+1);
                if(word1.charAt(i)==word2.charAt(j)) f[i][j]=Math.min(f[i][j],f[i-1][j-1]);
                else f[i][j]=Math.min(f[i][j],f[i-1][j-1]+1);
            }
        }

        return f[len1-1][len2-1];
    }
}
