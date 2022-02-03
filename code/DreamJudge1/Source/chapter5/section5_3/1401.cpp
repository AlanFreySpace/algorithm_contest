#include <string>
#include <iostream>
using namespace std;

struct Node{
    char element;
    Node *lc=NULL,*rc=NULL;
};

/*
根据前序和中序真实的创建一棵二叉树,实际上由题目要求不需创建一棵二叉树,
见第二版代码
substr(m,n)是从下标m开始截取长度为n的字符串,若下标越界则返回空串,
若m未越界,但n越界则截到末尾,若只给定m,则从下标m截到末尾
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
