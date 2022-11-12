package week3;

public class p48 {
	public void rotate(int[][] matrix) {
        int n=matrix.length;
        //沿纵向对称轴翻折
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[n-i-1][j];
                matrix[n-i-1][j]=tmp;
            }
        }
        //沿主对角线翻折
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tmp;
            }
        }
    }
}
