package test4;

import java.util.Scanner;

/*
 * 递归的方法解决汉诺塔问题。
 */
public class CD22_P13_v1 {
	public int process(int num,String left,String mid,String right,String from,String to){
        if(num==1){
            if(from.equals(mid)||to.equals(mid)){
                System.out.println("Move 1 from "+from+" to "+to);
                return 1;
            }else{
                System.out.println("Move 1 from "+from+" to "+mid);
                System.out.println("Move 1 from "+mid+" to "+to);
                return 2;
            }
        }
        
        if(from.equals(mid)||to.equals(mid)){
            String another=from.equals(right)||to.equals(right)?left:right;
            int part1=process(num-1,left,mid,right,from,another);
            int part2=1;
            System.out.println("Move "+num+" from "+from+" to "+to);
            int part3=process(num-1,left,mid,right,another,to);
            return part1+part2+part3;
        }
        int part1=process(num-1,left,mid,right,from,to);
        int part2=1;
        System.out.println("Move "+num+" from "+from+" to "+mid);
        int part3=process(num-1,left,mid,right,to,from);
        int part4=1;
        System.out.println("Move "+num+" from "+mid+" to "+to);
        int part5=process(num-1,left,mid,right,from,to);
        return part1+part2+part3+part4+part5;
    }
    
    public int hanoi1(int n,String left,String mid,String right){
        if(n<1)
            return 0;
        return process(n,left,mid,right,left,right);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        CD22_P13_v1 ma=new CD22_P13_v1();
        System.out.print("It will move "+ma.hanoi1(n,"left","mid","right")+" steps.");
        sc.close();
    }
}
