package test6;

import java.util.Scanner;

/*
 * ���ղŵĵݹ鷽����Ϊѭ���Խ���ʱ�临�Ӷȣ�cur�ǵ�ǰ
 * i��p(i),��һ��i��p(i+1)
 * next��p(i+2)
 */
public class CD46_P238_v2{
    public int getNum(char[] c){
        int cur=(c[c.length-1]==0?0:1);
        int next=1;
        int tmp=0;
        for(int i=c.length-2;i>=0;i--){
            if(c[i]=='0'){
                next=cur;
                cur=0;
            }else{
                tmp=cur;
                if((c[i]-'0')*10+(c[i+1]-'0')<27)
                    cur=(cur+next)%1000000007;
                next=tmp;
            }
        }
        return cur;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        char[] c=str.toCharArray();
        CD46_P238_v2 ma=new CD46_P238_v2();
        System.out.print(ma.getNum(c));
        sc.close();
    }
}
