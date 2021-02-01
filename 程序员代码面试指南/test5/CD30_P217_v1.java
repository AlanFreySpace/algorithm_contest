package test5;

import java.util.Scanner;

/*
 * 汉诺塔问题原问题的解
 */
public class CD30_P217_v1 {
	/*
	 * process过程表示将n个圆盘从from移动到to的步骤：
	 * 1.若只有一个圆盘，则直接从from移动到to即可
	 * 2.若圆盘多于一个：
	 *   先将n-1个圆盘从from移动到中转圆盘mid：process(n-1,from,to,mid)
	 *   将第n个圆盘从from移动到to
	 *   将n-1个圆盘从mid移动到to:process(n-1,mid,from,to);
	 */
	public void process(int n,int from,int mid,int to){
        if(n==1)
            System.out.println("Move "+n+" from "+from+" to "+to);
        else{
            process(n-1,from,to,mid);
            System.out.println("Move "+n+" from "+from+" to "+to);
            process(n-1,mid,from,to);
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        CD30_P217_v1 ma=new CD30_P217_v1();
        ma.process(n,1,2,3);
        sc.close();
    }
}
