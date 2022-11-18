package week4;

import java.util.ArrayList;
import java.util.List;

public class p54 {
	public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans=new ArrayList<>();
        int m=matrix.length;
        int n=matrix[0].length;
        int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
        boolean use[][]=new boolean[m][n];

        for(int i=0,x=0,y=0,k=0;i<m*n;i++){
            ans.add(matrix[y][x]);
            use[y][x]=true;

            int tmpy=y+dy[k],tmpx=x+dx[k];
            if(tmpy<0||tmpy>=m||tmpx<0||tmpx>=n||use[tmpy][tmpx]) k=(k+1)%4;
            y=y+dy[k];
            x=x+dx[k];
        }

        return ans;
    }
}
