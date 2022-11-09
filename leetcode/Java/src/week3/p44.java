package week3;

public class p44 {
	public boolean isMatch(String s, String p) {
        s=' '+s;
        p=' '+p;
        int n=s.length(),m=p.length();
        boolean f[][]=new boolean[n][m];

        f[0][0]=true;
        for(int j=1;j<m;j++){//应注意i=0时如何得到f[0][j]的值
            if(p.charAt(j)!='*') f[0][j]=false;
            else f[0][j]=f[0][j-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(p.charAt(j)=='?'||s.charAt(i)==p.charAt(j))
                    f[i][j]=f[i-1][j-1];
                else if(p.charAt(j)=='*')
                    f[i][j]=f[i][j-1]||f[i-1][j];
            }
        }

        return f[n-1][m-1];
    }
}
