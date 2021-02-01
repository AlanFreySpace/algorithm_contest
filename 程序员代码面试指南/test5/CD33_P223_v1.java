package test5;

import java.util.Scanner;

/*
 * ��̬�滮��������ִ����⣬ʱ�临�Ӷȣ�O(M*N)
 * �ռ临�Ӷȣ�O(M*N),ʵ���Ͽռ临�Ӷȿ����Ż���O(1)
 * ��v2�����
 */
public class CD33_P223_v1 {
	public int[][] getdp(char[] c1,char[] c2){
        int m=c1.length,n=c2.length;
        int[][] dp=new int[m][n];
        for(int i=0;i<m;i++)
            if(c2[0]==c1[i])
                dp[i][0]=1;
        for(int i=1;i<n;i++)
            if(c1[0]==c2[i])
                dp[0][i]=1;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                if(c1[i]==c2[j])
                    dp[i][j]=dp[i-1][j-1]+1;
        return dp;
    }
    
    public String getlcst(String s1,String s2){
        char[] c1=s1.toCharArray();
        char[] c2=s2.toCharArray();
        int[][] dp=getdp(c1,c2);
        int m=c1.length-1,n=c2.length-1;
        int max=0,end=0;
        /*
         * ע��������<=��������Щ������ͨ������
         * Ҫϸ�ģ�
         */
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                if(dp[i][j]>max){
                    max=dp[i][j];
                    end=i;
                }
        return s1.substring(end-max+1,end+1);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s1=sc.next();
        String s2=sc.next();
        CD33_P223_v1 ma=new CD33_P223_v1();
        String res=ma.getlcst(s1,s2);
        if(res.equals(""))
            System.out.print(-1);
        else
            System.out.print(res);
        sc.close();
    }
}
