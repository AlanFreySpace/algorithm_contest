package test6;

import java.util.Scanner;

/*
 * 动态规划解龙与地下城，未使用空间压缩，空间复杂度较高
 * 注意，时刻要确保血量大于等于1
 */
public class CD45_P236_v1{
    public int minBlood(int[][] map){
        int row=map.length,col=map[0].length;
        int[][] dp=new int[row][col];
        dp[row-1][col-1]=(map[row-1][col-1]<0?1-map[row-1][col-1]:1);
        for(int i=col-2;i>=0;i--)
            dp[row-1][i]=Math.max(dp[row-1][i+1]-map[row-1][i],1);
        int right=0,down=0;
        for(int i=row-2;i>=0;i--){
            dp[i][col-1]=Math.max(dp[i+1][col-1]-map[i][col-1],1);
            for(int j=col-2;j>=0;j--){
                right=Math.max(dp[i][j+1]-map[i][j],1);
                down=Math.max(dp[i+1][j]-map[i][j],1);
                dp[i][j]=Math.min(right,down);
            }
        }
        return dp[0][0];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        int[][] map=new int[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                map[i][j]=sc.nextInt();
        CD45_P236_v1 ma=new CD45_P236_v1();
        System.out.print(ma.minBlood(map));
        sc.close();
    }
}
