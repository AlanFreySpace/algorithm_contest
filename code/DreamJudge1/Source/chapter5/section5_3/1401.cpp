#include <string>
#include <iostream>
using namespace std;

struct Node{
    char element;
    Node *lc=NULL,*rc=NULL;
};

/*
����ǰ���������ʵ�Ĵ���һ�ö�����,ʵ��������ĿҪ���贴��һ�ö�����,
���ڶ������
substr(m,n)�Ǵ��±�m��ʼ��ȡ����Ϊn���ַ���,���±�Խ���򷵻ؿմ�,
��mδԽ��,��nԽ����ص�ĩβ,��ֻ����m,����±�m�ص�ĩβ
*/
void createTree(string pre,string in,Node* &root){
    if(pre.size()==0) return;
    char r=pre[0];
    root=new Node();
    root->element=r;
    int index=in.find(r);
    string leftpre=pre.substr(1,index);
    string rightpre=pre.substr(index+1);
    string leftin=in.substr(0,index);
    string rightin=in.substr(index+1);
    createTree(leftpre,leftin,root->lc);
    createTree(rightpre,rightin,root->rc);
}

void postOrder(Node* root){
    if(root){
        postOrder(root->lc);
        postOrder(root->rc);
        cout<<root->element;
    }
}

int main(){
    string pre,in;
    while(cin>>pre>>in){
        Node *root=NULL;
        createTree(pre,in,root);
        postOrder(root);
        cout<<endl;
    }
    return 0;
}
