package test6;

import java.util.Scanner;

//Node的定义见CD48
public class CD49_P42_v1{
    public Node removeK(Node head,int n,int k){
        Node last=head;
        if(k==n)//删除首节点
            head=head.next;
        else{
            for(int i=n-k-1;i>0;i--)
                last=last.next; //待删除结点的前一个节点
            if(k==1)//删除尾节点
                last.next=null;
            else //删除中间节点
                last.next=last.next.next;
        }
        return head;
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        Node head=new Node(sc.nextInt());
        Node tmp=head;
        Node in=head;
        for(int i=1;i<n;i++){
            tmp=head;
            head=new Node(sc.nextInt());
            tmp.next=head;
        }
        CD49_P42_v1 ma=new CD49_P42_v1();
        Node out=ma.removeK(in,n,k);
        StringBuilder sb=new StringBuilder();
        while(out!=null){
            sb.append(out.value+" ");
            out=out.next;
        }
        System.out.print(sb.toString());
        sc.close();
    }
}