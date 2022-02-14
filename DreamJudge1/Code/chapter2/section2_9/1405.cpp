#include <stdio.h>
using namespace std;

#define INF 1e9;

struct Node{
    int num;
    Node *next=NULL;
};

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        Node *head=new Node(),*tail=new Node(),*cur=new Node();
        head->num=-INF;
        tail->num=INF;
        scanf("%d",&cur->num);
        head->next=cur;
        cur->next=tail;
        for(int i=1;i<n;i++){
            Node *p=new Node();
            scanf("%d",&p->num);
            Node *before=head;
            cur=before->next;
            Node *after=cur->next;
            while(cur){
                if(cur->num<p->num){
                    before=cur;
                    cur=after;
                    after=cur->next;
                }
                else{
                    before->next=p;
                    p->next=cur;
                    break;
                }
            }
        }
        cur=head->next;
        while(cur->next){
            printf("%d ",cur->num);
            cur=cur->next;
        }
        printf("\n");
    }
    return 0;
}
