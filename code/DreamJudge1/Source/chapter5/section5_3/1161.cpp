#include <stdio.h>
#include <string.h>
using namespace std;

struct Node{
    char element;
    Node *lc=NULL,*rc=NULL;
};
/*
ע�Ȿ��Ĳ���������ĩβ�Ŀ���û�б��,
���Ҫ�ó��ȸ����ж�
������:XYOPBMA#WFXGZD
*/
void createTree(Node* &root,int &index,char* s,int len){
    if(index>=len) return;
    char tmp=s[index];
    index++;
    if(tmp!='#'){
        root=new Node();
        root->element=tmp;
        createTree(root->lc,index,s,len);
        createTree(root->rc,index,s,len);
    }
}

void InOrder(Node* root){
    if(root){
        InOrder(root->lc);
        printf("%c ",root->element);
        InOrder(root->rc);
    }
}

int main(){
    char s[105];
    while(gets(s)!=NULL){
        int index=0,len=strlen(s);
        Node *root=NULL;
        createTree(root,index,s,len);
        InOrder(root);
        printf("\n");
    }
    return 0;
}
