package test5;

import java.util.Scanner;

class Node{
    int value;
    int arrNum;
    int index;
    public Node(int v,int a,int i){
        value=v;
        arrNum=a;
        index=i;
    }
}

public class CD34_P404_v1{
	//�Զ��е������ڵ���н���
    public void swap(Node[] n,int index1,int index2){
        Node tmp=n[index1];
        n[index1]=n[index2];
        n[index2]=tmp;
    }
    
    //����в���һ��Ԫ��(���˹���)
    public void insert(Node[] n,int index){
        while(index!=0){
            int parent=(index-1)/2;
            if(n[parent].value<n[index].value){
                swap(n,index,parent);
                index=parent;
            }
            else
                break;
        }
    }
    
    //���Ѷ�Ԫ�ػ�Ϊ��һ��Ԫ�أ��Զѽ��е���(���˹���)
    public void heapify(Node[] n,int index,int size){
        int left=2*index+1,right=2*index+2;
        int max=index;
        while(left<size){
           if(n[left].value>n[index].value)
               max=left;
           if(right<size&&n[right].value>n[max].value)
               max=right;
           if(max!=index)
               swap(n,index,max);
           else
               break;
           index=max;
           left=2*index+1;
           right=2*index+2;
        }
    }
    
    //�õ�����K��Ԫ��
    public void getTopK(int[][] m,int topK){
        int size=m.length;
        Node[] heap=new Node[size];
        for(int i=0;i<size;i++){
            int len=m[i].length-1;
            heap[i]=new Node(m[i][len],i,len);
            insert(heap,i);
        }
        for(int i=0;i<topK;i++){
            if(size==0)
                break;
            System.out.print(heap[0].value+" ");
            if(heap[0].index>0)
                heap[0].value=m[heap[0].arrNum][--heap[0].index];
            else
                swap(heap,0,--size);
            heapify(heap,0,size);
        }
    }
    
    /*
     * ��ʵ�ʵĲ��������У��е������鳤��Ϊ0��������62�е�
     * heap[i]=new Node(m[i][len],i,len);��Խ�籨��
     * ������룺
     * if(N==0){
                m[i]=new int[1];
                m[i][0]=Integer.MIN_VALUE;
            }
     */
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        int K=sc.nextInt();
        int[][] m=new int[T][];
        for(int i=0;i<T;i++){
            int N=sc.nextInt();
            if(N==0){
                m[i]=new int[1];
                m[i][0]=Integer.MIN_VALUE;
            }
            else m[i]=new int[N];
            for(int j=0;j<N;j++)
                m[i][j]=sc.nextInt();
        }
        CD34_P404_v1 ma=new CD34_P404_v1();
        ma.getTopK(m,K);
        sc.close();
    }
}
