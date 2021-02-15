package test7;

import java.util.Scanner;

/*
 * 利用叉乘解决问题，可以避免double精度损失过多
 */
public class CD59_P452_v2{
    public double crossProduct(double x1,double y1,double x2,double y2){
        double res=x1*y2-x2*y1;
        return res;
    }
    
    public boolean isInside(double x1,double y1,double x2,double y2,double x3,double y3,double x,double y){
        if(crossProduct(x2-x1,y2-y1,x3-x1,y3-y1)<=0){
            double tmp1=x1,tmp2=y1;
            x1=x3;
            y1=y3;
            x3=tmp1;
            y3=tmp2;
        }
        if(crossProduct(x-x1,y-y1,x2-x1,y2-y1)<0
           &&crossProduct(x-x3,y-y3,x1-x3,y1-y3)<0
           &&crossProduct(x-x2,y-y2,x3-x2,y3-y2)<0)
            return true;
        return false;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        double x1=sc.nextDouble(),y1=sc.nextDouble();
        double x2=sc.nextDouble(),y2=sc.nextDouble();
        double x3=sc.nextDouble(),y3=sc.nextDouble();
        double x=sc.nextDouble(),y=sc.nextDouble();
        CD59_P452_v2 ma=new CD59_P452_v2();
        if(ma.isInside(x1,y1,x2,y2,x3,y3,x,y)==true)
            System.out.print("Yes");
        else
            System.out.print("No");
        sc.close();
    }
}
