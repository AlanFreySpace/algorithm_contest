package test1;

import java.util.Scanner;

/*
 * ���ö�̬�滮�ķ�����δ�ռ�ѹ����
 * ʱ�䣬�ռ临�ӶȾ�ΪO(N*aim)
 */
public class _3CD12_P189_v2 {
	public int minCoin2(int[] arr,int aim){
        if(arr==null||arr.length==0||aim<0)
            return -1;
        int N=arr.length;
        int[][] dp=new int[N+1][aim+1];
        dp[N][0]=0;
        /*
         * ��̬�滮������һ�����𣬱��и������
         * ���ø��м����¸��ж�Ӧ��ֵ�Ļ��ҹ��ɸ���
         * ����Ǯ����Ҫ�����ٻ�������
         */
        //���һ����ƽ��������������
        for(int i=1;i<=aim;i++)
            dp[N][i]=-1;
        //���µ��ϣ����������
        for(int i=N-1;i>=0;i--){
            for(int j=0;j<=aim;j++){
                dp[i][j]=-1; //���ȳ�ʼ��Ϊ-1(������Ч)
                /*
                 * ����һ����Ч(����-1)���ɽ�Ҫ�û�����
                 * ����Ϊ�����û�����ֵi��������i������
                 * �Ļ�������Ļ�����
                 */
                if(dp[i+1][j]!=-1)
                    dp[i][j]=dp[i+1][j];
                /*
                 * �������������ֵi������һ�ż��ɣ���Ϊ
                 * ������ŵ�����������dp[i][j-arr[i]]
                 * �г��Թ���
                 */
                if(j-arr[i]>=0&&dp[i][j-arr[i]]!=-1){
                    if(dp[i][j]==-1)
                        dp[i][j]=dp[i][j-arr[i]]+1;
                    else
                        dp[i][j]=Math.min(dp[i][j-arr[i]]+1,dp[i][j]);
                }
            }
        }
        return dp[0][aim];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int aim=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        _3CD12_P189_v2 ma=new _3CD12_P189_v2();
        System.out.println(ma.minCoin2(arr,aim));
        sc.close();
    }
}
