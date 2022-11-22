package week4;

public class p59 {
	public int[][] generateMatrix(int n) {
        int[][] ans=new int[n][n];
        int[] dx={1,0,-1,0},dy={0,1,0,-1};
        int dir=0;

        for(int i=0,x=0,y=0;i<n*n;i++){
            ans[y][x]=i+1;
            int tmpx=x+dx[dir],tmpy=y+dy[dir];
            if(tmpx<0||tmpx>=n||tmpy<0||tmpy>=n||ans[tmpy][tmpx]!=0){
                dir=(dir+1)%4;
            }
            x=x+dx[dir];
            y=y+dy[dir];
        }
        return ans;
    }
}
