package test3;

import java.util.Scanner;

/*
 * ���ַ�����Ȼ�����ϸ��Ӷ�ΪO(N^2)(����101��v1������)��
 * ����Ϊ������һ���ַ�������ʽ�����ʵ������ʱ�䷴����
 */
public class _2CD188_P20_v2 {
	public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        StringBuilder sb=new StringBuilder();
         
        for(int i=0;i<arr.length;i++){
            int leftIndex=-1,rightIndex=-1,cur=i-1;
            while(cur>=0){
                if(arr[cur]<arr[i]){
                    leftIndex=cur;
                    break;
                }
                cur--;
            }
            cur=i+1;
            while(cur<arr.length){
                if(arr[cur]<arr[i]){
                    rightIndex=cur;
                    break;
                }
                cur++;
            }
            sb.append(leftIndex).append(" ").append(rightIndex).append("\n");
        }
         
        System.out.print(sb.toString());
        sc.close();
    }
}
