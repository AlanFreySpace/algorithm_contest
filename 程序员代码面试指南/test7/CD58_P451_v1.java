package test7;

import java.util.Scanner;

public class CD58_P451_v1{
    public boolean isInside(double x1,double y1,double x4,double y4,double x,double y){
        if(x<=x1||x>=x4||y<=y4||y>=y1)
            return false;
        return true;
    }
    
    public boolean isInside(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4,double x,double y){
        if(y1==y2)
            return isInside(x1,y1,x4,y4,x,y);
        x1-=x3;
        y1-=y3;
        x2-=x3;
        y2-=y3;
        x4-=x3;
        y4-=y3;
        x-=x3;
        y-=y3;
        double s=Math.sqrt(y4*y4+x4*x4);
        double sin=y4/s,cos=x4/s;
        double x1R=x1*cos+y1*sin,y1R=y1*cos-x1*sin;
        double x4R=x4*cos+y4*sin,y4R=y4*cos-x4*sin;
        double xR=x*cos+y*sin,yR=y*cos-x*sin;
        return isInside(x1R,y1R,x4R,y4R,xR,yR);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        double x1=sc.nextDouble(),y1=sc.nextDouble(),x2=sc.nextDouble(),y2=sc.nextDouble();
        double x3=sc.nextDouble(),y3=sc.nextDouble(),x4=sc.nextDouble(),y4=sc.nextDouble();
        double x=sc.nextDouble(),y=sc.nextDouble();
        CD58_P451_v1 ma=new CD58_P451_v1();
        if(ma.isInside(x1,y1,x2,y2,x3,y3,x4,y4,x,y)==true)
            System.out.print("Yes");
        else
            System.out.print("No");
        sc.close();
    }
}