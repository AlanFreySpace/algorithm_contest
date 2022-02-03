#include <stdio.h>
using namespace std;

struct Node{
    int element;
    Node *lc=NULL,*rc=NULL;
};
//注意构造二叉排序树的方法
void insertNode(int a,Node *root){
    Node *tmp=root,*before=NULL;
    int flag=0;
    while(tmp){
        before=tmp;
        if(a<tmp->element){
            flag=1;
            tmp=tmp->lc;
        }
        else if(a>tmp->element){
            flag=2;
            tmp=tmp->rc;
        }
        else break;
    }
    if(!tmp){
        tmp=new Node();
        tmp->element=a;
        if(flag==1) before->lc=tmp;
        else if(flag==2) before->rc=tmp;
    }
}

void preOrder(Node *root){
    if(root){
        printf("%d ",root->element);
        preOrder(root->lc);
        preOrder(root->rc);
    }
}

void inOrder(Node *root){
    if(root){
        inOrder(root->lc);
        printf("%d ",root->element);
        inOrder(root->rc);
    }
}

void postOrder(Node *root){
    if(root){
        postOrder(root->lc);
        postOrder(root->rc);
        printf("%d ",root->element);
    }
}


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        Node *root=new Node();
        int tmp;
        scanf("%d",&tmp);
        root->element=tmp;
        for(int i=1;i<n;i++){
            scanf("%d",&tmp);
            insertNode(tmp,root);
        }
        preOrder(root);
        printf("\n");
        inOrder(root);
        printf("\n");
        postOrder(root);
        printf("\n");
    }
    return 0;
}
