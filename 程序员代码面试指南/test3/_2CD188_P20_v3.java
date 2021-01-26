package test3;

import java.util.*;

//”≈ªØ¡ÀIO
public class _2CD188_P20_v3 {
	public int[][] getPosi(int[] arr){
        int[][] res=new int[arr.length][2];
        Stack<List<Integer>> stack=new Stack<List<Integer>>();
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
                ArrayList<Integer> list=new ArrayList<Integer>();
                list.add(i);
                stack.add(list);
            }
        }
         
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
        _2CD188_P20_v3 ma=new _2CD188_P20_v3();
        int[][] res=ma.getPosi(arr);
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<n;i++)
            sb.append(res[i][0]).append(" ").append(res[i][1]).append("\n");
        System.out.print(sb.toString());
        sc.close();
    }
}
