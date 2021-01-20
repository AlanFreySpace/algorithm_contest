package test1;

import java.util.Scanner;

/*
 * 利用空间压缩的方法优化空间复杂度
 */
public class _1CD186_P185_v2 {
	public int minPathSum2(int[][] a){
        if(a==null||a[0]==null||a.length==0||a[0].length==0)
            return 0;
        int less=Math.min(a.length,a[0].length);
        int more=Math.max(a.length,a[0].length);
        boolean rowmore=(more==a.length);
        int[] temp=new int[less];
        temp[0]=a[0][0];
        for(int i=1;i<less;i++)
            temp[i]=temp[i-1]+(rowmore?a[0][i]:a[i][0]);
        for(int i=1;i<more;i++){
            temp[0]+=rowmore?a[i][0]:a[0][i];
            for(int j=1;j<less;j++)
                temp[j]=Math.min(temp[j-1],temp[j])+(rowmore?a[i][j]:a[j][i]);
        }
        return temp[less-1];
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[][] a=new int[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]=sc.nextInt();
        _1CD186_P185_v2 ma=new _1CD186_P185_v2();
        System.out.println(ma.minPathSum2(a));
        sc.close();
    }
}
