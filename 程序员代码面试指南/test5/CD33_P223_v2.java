package test5;

import java.util.Scanner;

public class CD33_P223_v2 {
	/*
	 * 从右下到左上，再从左上到右上，这份代码空间复杂度
	 * 降到O(1),但显得繁琐，我们发现两个for循环里有很多
	 * 重复部分，更简洁的代码见书上。
	 */
	public String getlcst(String s1,String s2){
        char[] c1=s1.toCharArray();
        char[] c2=s2.toCharArray();
        int m=c1.length,n=c2.length;
        int i=m-1,dp=0,max=0,end=m-1;
        for(;i>=0;i--){
            dp=(c2[0]==c1[i]?1:0);
            if(max<dp){
                max=dp;
                end=i;
            }
            int row=i+1,col=1;
            while(row<m&&col<n){
                if(c1[row]==c2[col]){
                    dp++;
                    if(max<dp){
                        max=dp;
                        end=row;
                    }
                }
                else
                    dp=0;
                row++;
                col++;
            }
        }
        
        i=1;
        for(;i<n;i++){
            dp=(c1[0]==c2[i]?1:0);
            if(max<dp){
                max=dp;
                end=0;
            }
            int row=1,col=i+1;
            while(row<m&&col<n){
                if(c1[row]==c2[col]){
                    dp++;
                    if(max<dp){
                        max=dp;
                        end=row;
                    }
                }
                else
                    dp=0;
                row++;
                col++;
            }
        }
        return s1.substring(end-max+1,end+1);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s1=sc.next();
        String s2=sc.next();
        CD33_P223_v2 ma=new CD33_P223_v2();
        String res=ma.getlcst(s1,s2);
        if(res.equals(""))
            System.out.print(-1);
        else
            System.out.print(res);
        sc.close();
    }
}
