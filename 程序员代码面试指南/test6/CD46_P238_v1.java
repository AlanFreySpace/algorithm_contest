package test6;

import java.util.Scanner;

/*
 * �ݹ鷽ʽ������⣬�ݹ��������������ϣ�
 * process���������±��ַ����±�i��N-1
 * ��ת��Ϊ����ĸ���������
 */
public class CD46_P238_v1{
    public int process(char[] c,int i){
        if(i==c.length)
            return 1;
        if(c[i]=='0')
            return 0;
        int res=process(c,i+1);
        if(i+1<c.length&&((c[i]-'0')*10+(c[i+1]-'0'))<27)
           res+=process(c,i+2);
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        char[] c=str.toCharArray();
        CD46_P238_v1 ma=new CD46_P238_v1();
        System.out.print(ma.process(c,0));
        sc.close();
    }
}
