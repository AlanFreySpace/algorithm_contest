package week6;

public class p97_2 {
	public boolean isInterleave(String s1, String s2, String s3) {
        s1=" "+s1;
        s2=" "+s2;
        s3="  "+s3;
        int n=s1.length(),m=s2.length();
        if(n+m!=s3.length()) return false;
        boolean[] f=new boolean[m];

        for(int j=0;j<m;j++){
            if(s2.charAt(j)==s3.charAt(j+1)){
                f[j]=true;
            }else break;
        }
        // 注意此时容易写错,要对f[j]赋false值,以及21行应该先判断f[j]
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0){
                    if(f[j]&&s1.charAt(i)==s3.charAt(i+1)){
                        f[j]=true;
                    }
                    else f[j]=false;
                }
                else{
                    if(f[j]&&s1.charAt(i)==s3.charAt(i+j+1)){
                        f[j]=true;
                    }
                    else if(f[j-1]&&s2.charAt(j)==s3.charAt(i+j+1)){
                        f[j]=true;
                    }
                    else f[j]=false;
                }
            }
        }

        return f[m-1];
    }
}
