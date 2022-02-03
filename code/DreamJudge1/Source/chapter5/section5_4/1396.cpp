#include <stdio.h>
using namespace std;

struct Node{
    int element;
    Node *lc=NULL,*rc=NULL;
};

int insertNode(Node *root,int num){
    Node *tmp=root,*before=NULL;
    int flag=0;
    while(tmp){
        before=tmp;
        if(num<tmp->element){
            tmp=tmp->lc;
            flag=1;
        }
        else{
            tmp=tmp->rc;
            flag=2;
        }
    }
    tmp=new Node();
    tmp->element=num;
    if(flag==1) before->lc=tmp;
    else before->rc=tmp;
    return before->element;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int tmp;
        scanf("%d",&tmp);
        Node *root=new Node();
        root->element=tmp;
        printf("%d\n",-1);
        for(int i=1;i<n;i++){
            scanf("%d",&tmp);
            int ans=insertNode(root,tmp);
            printf("%d\n",ans);
        }
    }
    return 0;
}
