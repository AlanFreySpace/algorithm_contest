package test6;

import java.util.Scanner;

class Node{
    public int value;
    public Node next;
    public Node(int data){
        this.value=data;
    }
}
//StringBuilder可以一定程度上加快io速度
public class CD48_P41_v1{
    public String commonPart(Node head1,Node head2){
        StringBuilder sb=new StringBuilder();
        while(head1!=null&&head2!=null){
            if(head1.value<head2.value)
                head1=head1.next;
            else if(head1.value>head2.value)
                head2=head2.next;
            else{
                sb.append(head1.value+" ");
                head1=head1.next;
                head2=head2.next;
            }
        }
        return sb.toString();
    }
    
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Node head1=new Node(sc.nextInt());
        Node in1=head1;
        for(int i=1;i<n;i++){
            Node tmp=head1;
            head1=new Node(sc.nextInt());
            tmp.next=head1;
        }
        int m=sc.nextInt();
        Node head2=new Node(sc.nextInt());
        Node in2=head2;
        for(int i=1;i<m;i++){
            Node tmp=head2;
            head2=new Node(sc.nextInt());
            tmp.next=head2;
        }
        CD48_P41_v1 ma=new CD48_P41_v1();
        System.out.print(ma.commonPart(in1,in2));
        sc.close();
    }
}