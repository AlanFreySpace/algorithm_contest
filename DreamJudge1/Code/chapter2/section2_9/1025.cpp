#include <stdio.h>
using namespace std;

#define INF 1e9;

struct Node{
    int num;
    Node* next=NULL;
};

int main(){
    int s1,s2;
    scanf("%d",&s1);
    Node *head1=new Node();
    scanf("%d",&head1->num);
    Node *cur=head1;
    for(int i=1;i<s1;i++){
        Node *p=new Node();
        scanf("%d",&p->num);
        cur->next=p;
        cur=p;
    }//输入的第一个有序链表

    scanf("%d",&s2);
    Node* head2=new Node();
    scanf("%d",&head2->num);
    cur=head2;
    for(int i=1;i<s2;i++){
        Node *p=new Node();
        scanf("%d",&p->num);
        cur->next=p;
        cur=p;
    }//输入的第二个有序链表

    //模拟归并过程,得到有序链表
    Node *index1=head1,*index2=head2;
    Node *head=new Node();
    head->num=-INF;
    cur=head;
    while(index1&&index2){
        Node *p=new Node();
        if(index1->num<index2->num){
            p->num=index1->num;
            cur->next=p;
            index1=index1->next;
        }
        else{
            p->num=index2->num;
            cur->next=p;
            index2=index2->next;
        }
        cur=p;
    }
    while(index1){
        Node *p=new Node();
        p->num=index1->num;
        cur->next=p;
        index1=index1->next;
        cur=p;
    }
    while(index2){
        Node *p=new Node();
        p->num=index2->num;
        cur->next=p;
        index2=index2->next;
        cur=p;
    }

    cur=head->next;
    while(cur){
        printf("%d ",cur->num);
        cur=cur->next;
    }
    printf("\n");
    return 0;
}
