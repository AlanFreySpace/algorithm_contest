package test4;

import java.util.Scanner;

/*
 * 是对CD26题方法的进一步应用
 */
public class CD27_P398_v1 {
	public int maxSum(int[][] m){
        int max=Integer.MIN_VALUE;
        for(int i=0;i<m.length;i++){
            int[] h=new int[m[0].length];
            for(int j=i;j<m.length;j++){
                int cur=0;
                for(int k=0;k<m[0].length;k++){
                    h[k]+=m[j][k];
                    cur+=h[k];
                    max=Math.max(max,cur);
                    cur=(cur<0?0:cur);
                }
            }
        }
        return max;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int[][] arr=new int[N][M];
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                arr[i][j]=sc.nextInt();
        CD27_P398_v1 ma=new CD27_P398_v1();
        System.out.print(ma.maxSum(arr));
        sc.close();
    }
}
