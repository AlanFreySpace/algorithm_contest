package test;

import java.util.Scanner;

public class CD1_P376_v1 {
	public static boolean isContains(int[][] matrix,int K){
        int row=0;
        int column=matrix[0].length-1;
        while(row<matrix.length && column>-1){
            if(K==matrix[row][column])
                return true;
            else if(K<matrix[row][column])
                column--;
            else
                row++;
        }
        return false;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int K=sc.nextInt();
        int[][] matrix=new int[N][M];
        for(int i=0;i<N;i++)
           for(int j=0;j<M;j++)
               matrix[i][j]=sc.nextInt();
        boolean b=isContains(matrix,K);
        if(b==true)
            System.out.print("Yes");
        else
            System.out.print("No");
        sc.close();
    }
}
