package test7;

import java.util.Scanner;

/*
 * 该份代码逻辑正确，但因为double精度问题，导致
 * 面积对不准，从而判断经常出问题，得出错误的答案。
 */
public class CD59_P452_v1{
    public double getSideLen(double x1,double y1,double x2,double y2){
        double a=Math.abs(x1-x2);
        double b=Math.abs(y1-y2);
        return Math.sqrt(a*a+b*b);
    }
    
    public double getSquare(double x1,double y1,double x2,double y2,double x3,double y3){
        double len1=getSideLen(x1,y1,x2,y2);
        double len2=getSideLen(x1,y1,x3,y3);
        double len3=getSideLen(x2,y2,x3,y3);
        double p=(len1+len2+len3)/2;
        return Math.sqrt((p-len1)*(p-len2)*(p-len3)*p);
    }
    
    public boolean isInside(double x1,double y1,double x2,double y2,double x3,double y3,double x,double y){
        double s1=getSquare(x1,y1,x2,y2,x,y);
        double s2=getSquare(x1,y1,x3,y3,x,y);
        double s3=getSquare(x2,y2,x3,y3,x,y);
        double s=getSquare(x1,y1,x2,y2,x3,y3);
        return s1+s2+s3<=s;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        double x1=sc.nextDouble(),y1=sc.nextDouble();
        double x2=sc.nextDouble(),y2=sc.nextDouble();
        double x3=sc.nextDouble(),y3=sc.nextDouble();
        double x=sc.nextDouble(),y=sc.nextDouble();
        CD59_P452_v1 ma=new CD59_P452_v1();
        if(ma.isInside(x1,y1,x2,y2,x3,y3,x,y)==true)
            System.out.print("Yes");
        else
            System.out.print("No");
        sc.close();
    }
}
