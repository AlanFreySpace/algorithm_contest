package test6;

import java.util.Scanner;

/*
 * 利用空间压缩的技巧降低空间复杂度
 */
public class CD44_P233_v2{
    public boolean isCross(String str1,String str2,String aim){
        char[] c1=str1.toCharArray();
        char[] c2=str2.toCharArray();
        char[] ac=aim.toCharArray();
        if(c1.length+c2.length!=ac.length)
            return false;
        char[] longs=(c1.length>=c2.length?c1:c2);
        char[] shorts=(c1.length<c2.length?c1:c2);
        boolean[] dp=new boolean[shorts.length+1];
        dp[0]=true;
        for(int i=1;i<=shorts.length;i++){
            if(shorts[i-1]!=ac[i-1])
                break;
            dp[i]=true;
        }
        for(int i=1;i<=longs.length;i++){
            dp[0]=(dp[0]&&longs[i-1]==ac[i-1]);
            for(int j=1;j<=shorts.length;j++)
                if((dp[j-1]==true&&shorts[j-1]==ac[i+j-1])||(dp[j]==true&&longs[i-1]==ac[i+j-1]))
                    dp[j]=true;
        }
        return dp[shorts.length];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String str1=sc.next();
        String str2=sc.next();
        String aim=sc.next();
        CD44_P233_v2 ma=new CD44_P233_v2();
        if(ma.isCross(str1,str2,aim)==true)
            System.out.print("YES");
        else
            System.out.print("NO");
        sc.close();
    }
}
