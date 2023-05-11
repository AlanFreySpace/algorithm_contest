package week5;

import java.util.Stack;

public class p85 {
	// 与84题实质相同 都是单调栈的应用 可以很容易的转化为84题
	public int maximalRectangle(char[][] matrix) {
        int n=matrix.length,m=matrix[0].length;
        int[][] h=new int[n][m];

        for(int i=0;i<m;i++){
            if(matrix[0][i]=='1') h[0][i]=1;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') h[i][j]=h[i-1][j]+1;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int tmp=maxRectangle(h[i]);
            if(tmp>ans) ans=tmp;
        }

        return ans;
    }

	// 84题作为85题的子程序
    public int maxRectangle(int[] h){
        int n=h.length;
        int[] left=new int[n],right=new int[n];
        Stack<Integer> sk=new Stack<>();

        for(int i=0;i<n;i++){
            while(!sk.empty()&&h[sk.peek()]>=h[i]) sk.pop();
            if(sk.empty()) left[i]=-1;
            else left[i]=sk.peek();
            sk.push(i);
        }

        sk.clear();

        for(int i=n-1;i>=0;i--){
            while(!sk.empty()&&h[sk.peek()]>=h[i]) sk.pop();
            if(sk.empty()) right[i]=n;
            else right[i]=sk.peek();
            sk.push(i);
        }

        int res=0;
        for(int i=0;i<n;i++){
            int tmp=(right[i]-left[i]-1)*h[i];
            if(tmp>res) res=tmp;
        }

        return res;
    }
}
