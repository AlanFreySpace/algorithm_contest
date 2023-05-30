package week6;

public class p97_1 {
	// 空间复杂度为O(n*m)的动态规划 可对该空间进行压缩
	/*
	 * 另外应注意,这种dp方法始终可以保持|n-m|<=1的特性,通过分类讨论:
	 * 若f[i-1][j]或f[i][j-1]满足n-m=1或n=m=0或n-m=-1
	 * 则可推出f[i][j]也满足|n-m|<=1(数学归纳法)
	 */
	public boolean isInterleave(String s1, String s2, String s3) {
        s1=" "+s1;
        s2=" "+s2;
        s3="  "+s3;
        int n=s1.length(),m=s2.length();
        if(n+m!=s3.length()) return false;
        boolean[][] f=new boolean[n][m];

        for(int i=0;i<m;i++){
            if(s2.charAt(i)==s3.charAt(i+1)){
                f[0][i]=true;
            }else break;
        }

        for(int i=0;i<n;i++){
            if(s1.charAt(i)==s3.charAt(i+1)){
                f[i][0]=true;
            }else break;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(f[i-1][j]&&s1.charAt(i)==s3.charAt(i+j+1)){
                    f[i][j]=true;
                }
                else if(f[i][j-1]&&s2.charAt(j)==s3.charAt(i+j+1)){
                    f[i][j]=true;
                }
            }
        }

        return f[n-1][m-1];
    }
}
