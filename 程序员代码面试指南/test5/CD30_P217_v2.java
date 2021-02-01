package test5;

import java.util.Scanner;

/*
 * 递归方法解进阶版汉诺塔问题，可是通不过全部用例，这
 * 是在测试时卡栈空间的大小了。由于递归方法会占用更多的
 * 栈空间，从而造成栈溢出：StackOverflowError
 */
public class CD30_P217_v2 {
	public int process(int[] arr,int i,int from,int mid,int to){
        if(i==-1)
            return 0;
        if(arr[i]==from)
            return process(arr,i-1,from,to,mid);
        else if(arr[i]==mid)
            return -1;
        else{
            int res=process(arr,i-1,mid,from,to);
            if(res==-1)
                return -1;
            /*
             * 此处注意运算优先级：1<<i+res等价于1<<(i+res),
             * 加号的运算优先级比位运算即<<的优先级高
             */
            return ((1<<i)+res)%1000000007;
        }
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        CD30_P217_v2 ma=new CD30_P217_v2();
        System.out.print(ma.process(arr,arr.length-1,1,2,3));
        sc.close();
    }
}
