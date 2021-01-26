package test3;
import java.util.*;

/*
 * 利用单调栈结构解决问题(没有重复元素版本)，
 * 时间复杂度为O(N)
 */
public class _1CD101_P20_v2 {
	public int[][] getPosi(int[] arr){
        int[][] res=new int[arr.length][2];
        Stack<Integer> stack=new Stack<Integer>();
        /*
         * 单调栈构造阶段，从栈底到栈顶对应arr中元素值
         * (严格)单调递增
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
        //清算阶段
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
