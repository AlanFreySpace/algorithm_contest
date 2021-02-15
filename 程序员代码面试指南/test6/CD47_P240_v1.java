package test6;

import java.util.Scanner;

/*
 * 递归方法解决，时间复杂度过高
 */
public class CD47_P240_v1{
    public int process(char[] c,boolean desired,int l,int r){
        if(l==r){
            if(desired)
                return c[l]=='1'?1:0;
            else
                return c[l]=='1'?0:1;
        }
        int res=0;
        if(desired){
            for(int i=l+1;i<r;i+=2){
                switch(c[i]){
                    case '&':
                        res+=process(c,true,l,i-1)*process(c,true,i+1,r);
                        break;
                    case '|':
                        res+=process(c,true,l,i-1)*process(c,true,i+1,r)+process(c,true,l,i-1)*process(c,false,i+1,r)+
                            process(c,false,l,i-1)*process(c,true,i+1,r);
                        break;
                    case '^':
                        res+=process(c,true,l,i-1)*process(c,false,i+1,r)+process(c,false,l,i-1)*process(c,true,i+1,r);
                        break;
                }
            }
        }
        else{
            for(int i=l+1;i<r;i+=2){
                switch(c[i]){
                    case '&':
                        res+=process(c,true,l,i-1)*process(c,false,i+1,r)+process(c,false,l,i-1)*process(c,true,i+1,r)+
                            process(c,false,l,i-1)*process(c,false,i+1,r);
                        break;
                    case '|':
                        res+=process(c,false,l,i-1)*process(c,false,i+1,r);
                        break;
                    case '^':
                        res+=process(c,true,l,i-1)*process(c,true,i+1,r)+process(c,false,l,i-1)*process(c,false,i+1,r);
                        break;
                }
            }
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String exp=sc.next();
        char[] c=exp.toCharArray();
        String de=sc.next();
        boolean desired=false;
        if(de.equals("true"))
            desired=true;
        CD47_P240_v1 ma=new CD47_P240_v1();
        System.out.print(ma.process(c,desired,0,c.length-1));
        sc.close();
    }
}
