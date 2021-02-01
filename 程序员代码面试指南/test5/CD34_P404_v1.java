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
	//对堆中的两个节点进行交换
    public void swap(Node[] n,int index1,int index2){
        Node tmp=n[index1];
        n[index1]=n[index2];
        n[index2]=tmp;
    }
    
    //向堆中插入一个元素(上滤过程)
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
    
    //将堆顶元素换为另一个元素，对堆进行调整(下滤过程)
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
    
    //得到最大的K个元素
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
     * 在实际的测试用例中，有的子数组长度为0，这样在62行的
     * heap[i]=new Node(m[i][len],i,len);会越界报错，
     * 因此引入：
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
