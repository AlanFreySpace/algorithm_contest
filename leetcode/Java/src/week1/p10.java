package week1;

public class p10 {
	public boolean isMatch(String s, String p) {
        int n=s.length(),m=p.length();
        s=' '+s;
        p=' '+p;

        Boolean[][] f=new Boolean[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++) f[i][j]=false;
        }
        f[0][0]=true;

        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(j+1<=m&&p.charAt(j+1)=='*') continue;
                if(i!=0&&p.charAt(j)!='*') 
                    f[i][j]=(s.charAt(i)==p.charAt(j)||p.charAt(j)=='.')&&f[i-1][j-1];
                if(p.charAt(j)=='*')
                    f[i][j]=f[i][j-2]||(i!=0&&f[i-1][j]&&(p.charAt(j-1)==s.charAt(i)||p.charAt(j-1)=='.'));
            }
        }
        return f[n][m];
    }
}
