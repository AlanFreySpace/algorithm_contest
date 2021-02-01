package test5;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*
 * 利用宽度优先搜索解决问题，相对于书上的条件判断，
 * 我用一圈0将原矩阵围了起来，避免条件判断
 */
public class CD38_P413_v1{
    public int minPathValue(int[][] m){
        int[][] map=new int[m.length][m[0].length];
        Queue<Integer> rq=new LinkedList<Integer>();
        Queue<Integer> cq=new LinkedList<Integer>();
        rq.add(1);
        cq.add(1);
        map[1][1]=1;
        int r=0,c=0;
        while(!rq.isEmpty()){
            r=rq.poll();
            c=cq.poll();
            if(r==map.length-2&&c==map[0].length-2)
                return map[r][c];
            walkTo(r-1,c,m,map,map[r][c],rq,cq);
            walkTo(r+1,c,m,map,map[r][c],rq,cq);
            walkTo(r,c-1,m,map,map[r][c],rq,cq);
            walkTo(r,c+1,m,map,map[r][c],rq,cq);
        }
        return -1;
    }
    
    public void walkTo(int r,int c,int[][] m,int[][] map,int pre,Queue<Integer> rq,Queue<Integer> cq){
        if(m[r][c]==0||map[r][c]!=0)
            return;
        map[r][c]=pre+1;
        rq.add(r);
        cq.add(c);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int[][] m=new int[N+2][M+2];
        for(int i=1;i<=N;i++){
            String tmp=sc.next();
            char[] tmp1=tmp.toCharArray();
            for(int j=1;j<=M;j++)
                m[i][j]=tmp1[j-1]-'0';
        }
        CD38_P413_v1 ma=new CD38_P413_v1();
        System.out.print(ma.minPathValue(m));
        sc.close();
    }
}