package test1;

import java.util.Scanner;

/*
 * 动态规划典型题，默认原数组a不可改变，未采用
 * 空间压缩的版本一，空间复杂度较高。
 */
public class _1CD186_P185_v1 {
	public int minPathSum(int[][] a){
        if(a==null||a[0]==null||a.length==0||a[0].length==0)
            return 0;
        int row=a.length,col=a[0].length;
        int[][] temp=new int[row][col];
        temp[0][0]=a[0][0];
        
        for(int i=1;i<row;i++)
            temp[i][0]=temp[i-1][0]+a[i][0];
        for(int i=1;i<col;i++)
            temp[0][i]=temp[0][i-1]+a[0][i];
        for(int i=1;i<row;i++)
            for(int j=1;j<col;j++)
                temp[i][j]=Math.min(temp[i-1][j],temp[i][j-1])+a[i][j];
        return temp[row-1][col-1];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[][] a=new int[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]=sc.nextInt();
        _1CD186_P185_v1 ma=new _1CD186_P185_v1();
        System.out.println(ma.minPathSum(a));
        sc.close();
    }
}
