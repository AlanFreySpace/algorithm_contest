package test7;

import java.util.HashSet;
import java.util.Scanner;

/*
 * hashset.add(E e)：返回boolean型，
 * 如果此 set 中尚未包含指定元素，则添加指定元素 返回true；
 * 如果此 set 已包含该元素，则该调用不更改 set 并返回 false。
 */
public class CD61_P457_v1{
    public boolean isPerfectRectangle(int[][] m){
        int mostLeft=Integer.MAX_VALUE;
        int mostRight=Integer.MIN_VALUE;
        int mostDown=Integer.MAX_VALUE;
        int mostUp=Integer.MIN_VALUE;
        HashSet<String> set=new HashSet<>();
        long area=0;
        for(int[] rec:m){
            mostLeft=Math.min(mostLeft,rec[0]);
            mostRight=Math.max(mostRight,rec[2]);
            mostDown=Math.min(mostDown,rec[1]);
            mostUp=Math.max(mostUp,rec[3]);
            area+=(rec[2]-rec[0])*(rec[3]-rec[1]);
            String leftDown=rec[0]+"_"+rec[1];
            String leftUp=rec[0]+"_"+rec[3];
            String rightDown=rec[2]+"_"+rec[1];
            String rightUp=rec[2]+"_"+rec[3];
            if(!set.add(leftDown)) set.remove(leftDown);
            if(!set.add(leftUp)) set.remove(leftUp);
            if(!set.add(rightDown)) set.remove(rightDown);
            if(!set.add(rightUp)) set.remove(rightUp);
        }
        if(!set.contains(mostLeft+"_"+mostDown)||
          !set.contains(mostLeft+"_"+mostUp)||
          !set.contains(mostRight+"_"+mostDown)||
          !set.contains(mostRight+"_"+mostUp)||
          !(set.size()==4))
            return false;
        return area==(mostRight-mostLeft)*(mostUp-mostDown);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int  N=sc.nextInt();
        int[][] m=new int[N][4];
        for(int i=0;i<N;i++)
            for(int j=0;j<4;j++)
                m[i][j]=sc.nextInt();
        CD61_P457_v1 ma=new CD61_P457_v1();
        if(ma.isPerfectRectangle(m))
            System.out.print("Yes");
        else
            System.out.print("No");
        sc.close();
    }
}
