package test7;

import java.util.Scanner;

/*
 * ͨ����һ��ϸ�µĹ۲���Ż����������ҹ�������res��
 * ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�Ҳ��ΪO(1)
 */
public class CD54_P439_v3{
    public long getWater(int[] arr){
        int L=1,R=arr.length-2;
        int leftMax=arr[L-1],rightMax=arr[R+1];
        long res=0;
        while(L<=R){
            if(leftMax<=rightMax){
                res+=Math.max(leftMax-arr[L],0);
                leftMax=Math.max(leftMax,arr[L++]);
            }
            else{
                res+=Math.max(rightMax-arr[R],0);
                rightMax=Math.max(rightMax,arr[R--]);
            }
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD54_P439_v3 ma=new CD54_P439_v3();
        System.out.print(ma.getWater(arr));
        sc.close();
    }
}