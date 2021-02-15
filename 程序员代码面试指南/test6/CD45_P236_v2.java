package test6;

import java.util.Scanner;

//利用空间压缩方法降低空间复杂度
public class CD45_P236_v2{
    public int minBlood(int[][] map){
        int row=map.length,col=map[0].length;
        int right=0,down=0;
        if(row>=col){//按行更新
            int[] dp=new int[col];
            dp[col-1]=Math.max(1-map[row-1][col-1],1);
            for(int i=col-2;i>=0;i--)
                dp[i]=Math.max(dp[i+1]-map[row-1][i],1);
            for(int i=row-2;i>=0;i--){
                dp[col-1]=Math.max(dp[col-1]-map[i][col-1],1);
                for(int j=col-2;j>=0;j--){
                    right=Math.max(dp[j+1]-map[i][j],1);
                    down=Math.max(dp[j]-map[i][j],1);
                    dp[j]=Math.min(right,down);
                }
            }
            return dp[0];
        }
        else{//按列更新
            int[] dp=new int[row];
            dp[row-1]=Math.max(1-map[row-1][col-1],1);
            for(int i=row-2;i>=0;i--)
                dp[i]=Math.max(dp[i+1]-map[i][col-1],1);
            for(int i=col-2;i>=0;i--){
                dp[row-1]=Math.max(dp[row-1]-map[row-1][i],1);
                for(int j=row-2;j>=0;j--){
                    right=Math.max(dp[j]-map[i][j],1);
                    down=Math.max(dp[j+1]-map[i][j],1);
                    dp[j]=Math.min(right,down);
                }
            }
            return dp[0];
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        int[][] map=new int[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                map[i][j]=sc.nextInt();
        CD45_P236_v2 ma=new CD45_P236_v2();
        System.out.print(ma.minBlood(map));
        sc.close();
    }
}
