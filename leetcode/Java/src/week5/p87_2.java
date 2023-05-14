package week5;

public class p87_2 {
	// 动态规划，时间复杂度O(n^4)
	public boolean isScramble(String s1, String s2) {
        int n=s1.length();
        boolean[][][] f=new boolean[n][n][n+1];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s1.charAt(i)==s2.charAt(j)) f[i][j][1]=true;
            }
        }

        for(int k=2;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                for(int j=0;j<=n-k;j++){
                    for(int u=1;u<k;u++){
                        if(f[i][j][u]&&f[i+u][j+u][k-u]){
                            f[i][j][k]=true;
                            break;
                        }
                        if(f[i][j+k-u][u]&&f[i+u][j][k-u]){
                            f[i][j][k]=true;
                            break;
                        }
                    }
                }
            }
        }

        return f[0][0][n];
    }
}
