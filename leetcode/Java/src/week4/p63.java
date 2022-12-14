package week4;

public class p63 {
	public int uniquePathsWithObstacles(int[][] grid) {
        int m=grid.length,n=grid[0].length;
        int[][] f=new int[m][n];

        for(int i=0;i<m;i++){
            if(grid[i][0]==0) f[i][0]=1;
            else break;
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]==0) f[0][j]=1;
            else break;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1) f[i][j]=0;
                else f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }

        return f[m-1][n-1];
    }
}
