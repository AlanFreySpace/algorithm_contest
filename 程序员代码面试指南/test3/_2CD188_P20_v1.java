package test3;
import java.util.*;

/*
 * 利用单调栈结构解决问题(有重复元素版本)，
 * 时间复杂度为O(N),但因为利用单调栈时，
 * 不是按元素下标从左到右遍历构建的答案，
 * 而是按元素大小构建的答案，因此没有办法
 * 像O(N^2)的算法那样构建一个字符串，一次性
 * 输出，导致这道题在牛客网上成了一个IO题！
 * 
 * update:实际上也可以优化IO，见版本三代码
 */
public class _2CD188_P20_v1 {
	public int[][] getPosi(int[] arr){
        int[][] res=new int[arr.length][2];
        //利用一个个List存放重复元素的下标
        Stack<List<Integer>> stack=new Stack<List<Integer>>();
        //单调栈构造阶段
        for(int i=0;i<arr.length;i++){
            while(!stack.isEmpty()&&arr[stack.peek().get(0)]>arr[i]){
                List<Integer> popIs=stack.pop();
                int leftIndex=(stack.isEmpty()?-1:stack.peek().get(stack.peek().size()-1));
                for(Integer p:popIs){
                    res[p][0]=leftIndex;
                    res[p][1]=i;
                }
            }
            if(!stack.isEmpty()&&arr[stack.peek().get(0)]==arr[i])
                stack.peek().add(i);
            else{
            	/*
            	 * 声明时，注意List<Integer> list=
            	 * new List<Integer>这种方式是不合法
            	 * 的！因为List是抽象类型。
            	 */
                ArrayList<Integer> list=new ArrayList<Integer>();
                list.add(i);
                stack.add(list);
            }
        }
        
        //清算阶段
        while(!stack.isEmpty()){
            List<Integer> popIs=stack.pop();
            int leftIndex=(stack.isEmpty()?-1:stack.peek().get(stack.peek().size()-1));
            for(Integer p:popIs){
                res[p][0]=leftIndex;
                res[p][1]=-1;
            }
        }
        return res;
    }
     
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++)
            arr[i]=sc.nextInt();
        _2CD188_P20_v1 ma=new _2CD188_P20_v1();
        int[][] res=ma.getPosi(arr);
        for(int i=0;i<n;i++)
            System.out.println(res[i][0]+" "+res[i][1]);
        sc.close();
    }
}
