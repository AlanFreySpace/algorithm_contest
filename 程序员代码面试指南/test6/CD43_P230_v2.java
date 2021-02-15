package test6;

import java.util.Scanner;

/*
 * ���ÿռ�ѹ���ķ������Ϳռ临�Ӷ�
 */
public class CD43_P230_v2{
    public int minCost(String str1,String str2,int ic,int dc,int rc){
        char[] c1=str1.toCharArray();
        char[] c2=str2.toCharArray();
        char[] shorts=c1.length<c2.length?c1:c2;
        char[] longs=c1.length>=c2.length?c1:c2;
        int[] dp=new int[shorts.length+1];
        if(c2.length>c1.length){
            int tmp=ic;
            ic=dc;
            dc=tmp;
        }
        for(int i=1;i<dp.length;i++)
            dp[i]=i*ic;
        for(int i=1;i<=longs.length;i++){
            int tmp=dp[0]; //�������Ϸ�ԭֵ
            dp[0]=i*dc;
            for(int j=1;j<=shorts.length;j++){
                int tmp1=dp[j];
                if(longs[i-1]==shorts[j-1])
                    dp[j]=tmp; //�����Ϸ�ԭֵ
                else
                    dp[j]=tmp+rc;
                dp[j]=Math.min(dp[j],dp[j-1]+ic);
                dp[j]=Math.min(dp[j],tmp1+dc);
                tmp=tmp1;
            }
        }
        return dp[shorts.length];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String str1=sc.next();
        String str2=sc.next();
        int ic=sc.nextInt();
        int dc=sc.nextInt();
        int rc=sc.nextInt();
        CD43_P230_v2 ma=new CD43_P230_v2();
        System.out.print(ma.minCost(str1,str2,ic,dc,rc));
        sc.close();
    }
}