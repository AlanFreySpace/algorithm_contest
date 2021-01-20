package test2;

import java.util.Scanner;

/*
 * ��һ���㷨��ʱ�临�Ӷ�ΪO(N*log N),�ϸ�
 */
public class CD14_P386_v1 {
	/*
	 * ���ö��ֲ��ң��õ����ڵ���num�������(�±���С)
	 * �����ֵ��±꣬����arr�Ѿ�����С����Ĵ����ź���
	 * ��û���������±꣬�򷵻�-1
	 */
	public int getLessIndex(int[] arr,int num){
        int low=0;
        int high=arr.length-1;
        int mid=0;
        int res=-1;
        while(low<=high){
            mid=(high+low)/2;
            if(arr[mid]>=num){
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
    
	/*
	 * helpArr:��������
	 * pre:�±�
	 * len:��ǰ�±�i��β�����з���Ҫ���������鳤��
	 * res:ȫ�ֽ�
	 */
    public int maxLength(int[] arr,int k){
        int[] helpArr=new int[arr.length+1];
        int sum=0;
        helpArr[0]=0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            helpArr[i+1]=Math.max(helpArr[i],sum);
        }
        sum=0;
        int pre=0;
        int len=0;
        int res=0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            pre=getLessIndex(helpArr,sum-k);
            len=(pre==-1?0:i-pre+1);
            res=Math.max(len,res);
        }
        return res;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int N=sc.nextInt();
        int k=sc.nextInt();
        int[] arr=new int[N];
        for(int i=0;i<N;i++)
            arr[i]=sc.nextInt();
        CD14_P386_v1 ma=new CD14_P386_v1();
        System.out.println(ma.maxLength(arr,k));
        sc.close();
    }
}
