package test6;

import java.util.Scanner;

public class CD47_P240_v2{
	//���ȼ����ʽ�Ƿ�Ϸ�
    public boolean isValid(char[] c){
        if(c.length%2==0)
            return false;
        for(int i=0;i<c.length;i+=2)
            if(c[i]!='0'&&c[i]!='1')
                return false;
        for(int i=1;i<c.length;i+=2)
            if(c[i]!='&'&&c[i]!='|'&&c[i]!='^')
                return false;
        return true;
    }
    /*
     * ��������ѭ���У��õ�c[j..i]����ɶ��ٸ�Ϊtrue/false
     * �ı��ʽ��Ϊ������k+1��ʾ���ŵ�λ�ã���c[j..i]���
     */
    public long getNum(char[] c,boolean desired){
        if(!isValid(c))
            return 0;
        long mod=1000000007;
        long[][] t=new long[c.length][c.length];
        long[][] f=new long[c.length][c.length];
        t[0][0]=(c[0]=='1'?1:0);
        f[0][0]=(c[0]=='0'?1:0);
        for(int i=2;i<c.length;i+=2){
            t[i][i]=(c[i]=='1'?1:0);
            f[i][i]=(c[i]=='0'?1:0);
            for(int j=i-2;j>=0;j-=2){
                for(int k=j;k<i;k+=2){
                    long TT=t[j][k]*t[k+2][i]%mod;
                    long TF=t[j][k]*f[k+2][i]%mod;
                    long FT=f[j][k]*t[k+2][i]%mod;
                    long FF=f[j][k]*f[k+2][i]%mod;
                    if(c[k+1]=='&'){
                        t[j][i]=(t[j][i]+TT)%mod;
                        f[j][i]=(f[j][i]+FT+TF+FF)%mod;
                    }
                    else if(c[k+1]=='|'){
                        t[j][i]=(t[j][i]+TF+FT+TT)%mod;
                        f[j][i]=(f[j][i]+FF)%mod;
                    }
                    else{
                        t[j][i]=(t[j][i]+TF+FT)%mod;
                        f[j][i]=(f[j][i]+TT+FF)%mod;
                    }
                }
            }
        }
        return desired?t[0][c.length-1]:f[0][c.length-1];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String exp=sc.next();
        char[] c=exp.toCharArray();
        String de=sc.next();
        boolean desired=false;
        if(de.equals("true"))
            desired=true;
        CD47_P240_v2 ma=new CD47_P240_v2();
        System.out.print(ma.getNum(c,desired));
        sc.close();
    }
}
