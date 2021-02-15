package test7;

import java.util.Scanner;

/*
 * ʱ�临�ӶȾ��ﵽ���ŵ�O(N),�ռ临�Ӷȴﵽ���ŵ�O(1)��
 * ˼·���ע�������P439CD54������ʢˮ�������
 */
public class CD63_P463_v3{
    public int maxABS(int[] arr){
        int max=Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++)
            max=Math.max(max,arr[i]);
        int res=max-Math.min(arr[0],arr[arr.length-1]);
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD63_P463_v3 ma=new CD63_P463_v3();
        System.out.print(ma.maxABS(arr));
        sc.close();
    }
}