package test6;

import java.util.Scanner;

//Node�Ķ����CD48
public class CD49_P42_v1{
    public Node removeK(Node head,int n,int k){
        Node last=head;
        if(k==n)//ɾ���׽ڵ�
            head=head.next;
        else{
            for(int i=n-k-1;i>0;i--)
                last=last.next; //��ɾ������ǰһ���ڵ�
            if(k==1)//ɾ��β�ڵ�
                last.next=null;
            else //ɾ���м�ڵ�
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