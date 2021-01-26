package test4;

import java.util.Scanner;

public class CD21_P392_v1 {
	/*
	 * 注意返回类型是long，否则测试数据会溢出
	 */
	public long merge(int[] s,int left,int mid,int right){
        int[] help=new int[right-left+1];
        int i=left,j=mid+1,hi=0;
        long smallSum=0;
        while(i<=mid&&j<=right){
            if(s[i]<=s[j]){
                smallSum+=s[i]*(right-j+1);
                help[hi++]=s[i++];
            }else
                help[hi++]=s[j++];
        }
        
        for(;i<=mid||j<=right;i++,j++)
            help[hi++]=(i<=mid?s[i]:s[j]);
        /*
         * 注意这里help.length处别写成right-left+1了，因为
         * 下一句对left的值做了更改
         */
        for(int k=0;k<help.length;k++)
            s[left++]=help[k];
        return smallSum;
    }
    
    public long divide(int[] s,int l,int r){
        if(l==r)
            return 0;
        int mid=(l+r)/2;
        return divide(s,l,mid)+divide(s,mid+1,r)+merge(s,l,mid,r);
    }
    
    public long getSmallSum(int[] s){
        return divide(s,0,s.length-1);
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] s=new int[N];
        for(int  i=0;i<N;i++)
            s[i]=sc.nextInt();
        CD21_P392_v1 ma=new CD21_P392_v1();
        System.out.print(ma.getSmallSum(s));
        sc.close();
    }
}
