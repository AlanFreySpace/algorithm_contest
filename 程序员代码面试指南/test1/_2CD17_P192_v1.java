package test1;

import java.util.Scanner;

/*
 * �����ݹ鷽��
 */
public class _2CD17_P192_v1 {
	//walk�����Ǽ�����Ҫ�ı����ݹ鳢�Թ��̣����п��ҳ���̬�滮
    public int walk(int N,int cur,int rest,int P){
        if(rest==0)
            return cur==P?1:0;
        if(cur==1)
            return walk(N,2,rest-1,P);
        if(cur==N)
            return walk(N,N-1,rest-1,P);
        return walk(N,cur-1,rest-1,P)+walk(N,cur+1,rest-1,P);
    }
    
    public int way1(int N,int M,int K,int P){
        if(N<2||M<1||M>N||K<1||P<1||P>N)
            return 0;
        return walk(N,M,K,P);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int M=sc.nextInt();
        int K=sc.nextInt();
        int P=sc.nextInt();
        _2CD17_P192_v1 ma=new _2CD17_P192_v1();
        //����ȡģ�ǲ��еģ�����ԭ�����һ�����
        int ans=(int) (ma.way1(N,M,K,P)%(Math.pow(10, 9)+7));
        System.out.println(ans);
        sc.close();
    }
}
