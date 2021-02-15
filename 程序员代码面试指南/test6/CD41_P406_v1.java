package test6;

import java.util.Scanner;

public class CD41_P406_v1{
	/*
	 * 对矩阵进行预处理，得到dp矩阵
	 */
    public void  getdp(int[][] m,int[][] right,int[][] down){
        int row=m.length,col=m[0].length;
        if(m[row-1][col-1]==1){
            right[row-1][col-1]=1;
            down[row-1][col-1]=1;
        }
        for(int i=row-2;i>=0;i--)
            if(m[i][col-1]==1){
                right[i][col-1]=1;
                down[i][col-1]=down[i+1][col-1]+1;
            }
        for(int i=col-2;i>=0;i--)
            if(m[row-1][i]==1){
                right[row-1][i]=right[row-1][i+1]+1;
                down[row-1][i]=1;
            }
        for(int i=row-2;i>=0;i--)
            for(int j=col-2;j>=0;j--)
                if(m[i][j]==1){
                    right[i][j]=right[i][j+1]+1;
                    down[i][j]=down[i+1][j]+1;
                }
    }
    
    //判断是否有边框为size大小的正方形
    public boolean hasSize(int[][] right,int[][] down,int size){
        int row=right.length,col=right[0].length;
        for(int i=0;i<row-size+1;i++)
            for(int j=0;j<col-size+1;j++)
                if(right[i][j]>=size&&down[i][j]>=size&&down[i][j+size-1]>=size&&right[i+size-1][j]>=size)
                    return true;
        return false;
    }
    
    public int getMax(int[][] m){
        int[][] right=new int[m.length][m[0].length];
        int[][] down=new int[m.length][m[0].length];
        getdp(m,right,down);
        for(int i=Math.min(m.length,m[0].length);i>0;i--)
            if(hasSize(right,down,i))
                return i;
        return 0;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[][] m=new int[N][N];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                m[i][j]=sc.nextInt();
        CD41_P406_v1 ma=new CD41_P406_v1();
        System.out.print(ma.getMax(m));
        sc.close();
    }
}