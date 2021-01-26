package test3;

import java.util.Scanner;
import java.util.Stack;

/*
 * ��������Ӿ�������ʱ��Ŀ������һ��������ͬ
 * �������õ���ջ�ṹ��Ŀ�Ĳ��Ǿ�ȷ�����Ԫ��
 * ��������ı���С��Ԫ�ص�λ�ã�����������
 * �����������ʹ����height�����ظ�Ԫ�أ�Ҳ����
 * ����List����Ϊ�ýⷨ����ʹ����ȷ�����ֵ����
 * ����������ֵ��
 */
public class _3CD16_P26_v1 {
	public int getCurMax(int[] height){
        int curMax=0;
        Stack<Integer> stack=new Stack<Integer>();
        for(int i=0;i<height.length;i++){
            while(!stack.isEmpty()&&height[i]<=height[stack.peek()]){
                int h=height[stack.pop()];
                int leftIndex=(stack.isEmpty()?-1:stack.peek());
                int s=(i-leftIndex-1)*h;
                curMax=Math.max(curMax,s);
            }
            stack.push(i);
        }
        
        while(!stack.empty()){
            int h=height[stack.pop()];
            int leftIndex=(stack.isEmpty()?-1:stack.peek());
            int s=(height.length-leftIndex-1)*h;
            curMax=Math.max(curMax,s);
        }
        return curMax;
    }
    
    public int getMax(int[][] map){
        int maxArea=0;
        int[] height=new int[map[0].length];
        for(int i=0;i<map.length;i++){
            for(int j=0;j<map[0].length;j++)
                height[j]=(map[i][j]==0?0:height[j]+1);
            maxArea=Math.max(getCurMax(height),maxArea);
        }
        return maxArea;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[][] map=new int[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                map[i][j]=sc.nextInt();
        _3CD16_P26_v1 ma=new _3CD16_P26_v1();
        System.out.print(ma.getMax(map));
        sc.close();
    }
}
