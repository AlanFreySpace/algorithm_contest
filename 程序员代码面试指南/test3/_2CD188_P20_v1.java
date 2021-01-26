package test3;
import java.util.*;

/*
 * ���õ���ջ�ṹ�������(���ظ�Ԫ�ذ汾)��
 * ʱ�临�Ӷ�ΪO(N),����Ϊ���õ���ջʱ��
 * ���ǰ�Ԫ���±�����ұ��������Ĵ𰸣�
 * ���ǰ�Ԫ�ش�С�����Ĵ𰸣����û�а취
 * ��O(N^2)���㷨��������һ���ַ�����һ����
 * ����������������ţ�����ϳ���һ��IO�⣡
 * 
 * update:ʵ����Ҳ�����Ż�IO�����汾������
 */
public class _2CD188_P20_v1 {
	public int[][] getPosi(int[] arr){
        int[][] res=new int[arr.length][2];
        //����һ����List����ظ�Ԫ�ص��±�
        Stack<List<Integer>> stack=new Stack<List<Integer>>();
        //����ջ����׶�
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
            	 * ����ʱ��ע��List<Integer> list=
            	 * new List<Integer>���ַ�ʽ�ǲ��Ϸ�
            	 * �ģ���ΪList�ǳ������͡�
            	 */
                ArrayList<Integer> list=new ArrayList<Integer>();
                list.add(i);
                stack.add(list);
            }
        }
        
        //����׶�
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
