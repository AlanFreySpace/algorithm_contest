package test5;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/*
 *  该题目对Java面向对象的编程方法进行了细致考察，也有一定
 *  思维难度，注意Envelope类和EnvelopeComparator的写法，注意
 *  对compare方法的重写，以实现我们对信封的排序
 *  compare方法：若返回值小于0，则e1排在e2前面，否则
 *  e1排在e2后面
 */
class Envelope{
    int len;
    int wid;
    public Envelope(int length,int width){
        len=length;
        wid=width;
    }
}

class EnvelopeComparator implements Comparator<Envelope>{
    @Override
    public int compare(Envelope e1,Envelope e2){
        return e1.len==e2.len?e2.wid-e1.wid:e1.len-e2.len;
    }
}

public class CD29_P214_v1 {
	public Envelope[] getSortedEnvelope(int[][] matrix){
        Envelope[] res=new Envelope[matrix.length];
        for(int i=0;i<matrix.length;i++)
            res[i]=new Envelope(matrix[i][0],matrix[i][1]);
        Arrays.sort(res,new EnvelopeComparator());
        return res;
    }
    
    public int maxNum(Envelope[] e){
        int[] ends=new int[e.length];
        ends[0]=e[0].wid;
        int l=0,r=0,m=0,right=0;
        for(int i=1;i<e.length;i++){
            l=0;
            r=right;
            while(l<=r){
                m=(l+r)/2;
                if(ends[m]<e[i].wid)
                    l=m+1;
                else
                    r=m-1;
            }
            ends[l]=e[i].wid;
            right=Math.max(right,l);
        }
        return right+1;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][] matrix=new int[n][2];
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
                matrix[i][j]=sc.nextInt();
        CD29_P214_v1 ma=new CD29_P214_v1();
        Envelope[] res=ma.getSortedEnvelope(matrix);
        System.out.print(ma.maxNum(res));
        sc.close();
    }
}
