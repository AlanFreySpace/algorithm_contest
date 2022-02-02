#include <stdio.h>
#include <string.h>
using namespace std;

struct Node{
    char element;
    Node *lc=NULL,*rc=NULL;
};
/*
注意本题的测试数据中末尾的空树没有标出,
因此要用长度辅助判断
如数据:XYOPBMA#WFXGZD
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
