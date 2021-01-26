package test3;
import java.util.*;

/*
 * ���õ���ջ�ṹ�������(û���ظ�Ԫ�ذ汾)��
 * ʱ�临�Ӷ�ΪO(N)
 */
public class _1CD101_P20_v2 {
	public int[][] getPosi(int[] arr){
        int[][] res=new int[arr.length][2];
        Stack<Integer> stack=new Stack<Integer>();
        /*
         * ����ջ����׶Σ���ջ�׵�ջ����Ӧarr��Ԫ��ֵ
         * (�ϸ�)��������
         */
        for(int i=0;i<arr.length;i++){
            while(!stack.isEmpty()&&arr[stack.peek()]>arr[i]){
                int popIndex=stack.pop();
                int leftIndex=(stack.isEmpty()?-1:stack.peek());
                res[popIndex][0]=leftIndex;
                res[popIndex][1]=i;
            }
            stack.push(i);
        }
        //����׶�
        while(!stack.isEmpty()){
            int popIndex=stack.pop();
            int leftIndex=(stack.isEmpty()?-1:stack.peek());
            res[popIndex][0]=leftIndex;
            res[popIndex][1]=-1;
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        _1CD101_P20_v2 ma=new _1CD101_P20_v2();
        int[][] res=ma.getPosi(arr);
        for(int i=0;i<n;i++)
            System.out.println(res[i][0]+" "+res[i][1]);
        sc.close();
    }
}
