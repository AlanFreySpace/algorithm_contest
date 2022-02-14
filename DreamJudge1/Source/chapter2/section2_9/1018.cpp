#include <stdio.h>
using namespace std;

struct Node{
    int num;
    Node* next=NULL;
};

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        Node *first=new Node();
        first->num=1;
        Node *cur=first;
        for(int i=2;i<=n;i++){
            Node *p=new Node();
            p->num=i;
            cur->next=p;
            p->next=first;
            cur=p;
        }//构造循环链表

        cur=first;
        for(int i=n;i>1;i--){
            Node *before=cur->next;
            Node *now=before->next;
            cur=now->next;
            before->next=cur;
        }//击鼓传花
        printf("%d\n",cur->num);
    }
    return 0;
}
