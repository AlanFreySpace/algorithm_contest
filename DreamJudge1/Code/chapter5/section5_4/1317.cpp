#include <iostream>
#include <string>
using namespace std;

struct Node{
    char element;
    Node *lc=NULL,*rc=NULL;
};
//要点:根据前序和中序遍历唯一确定二叉树,判断两二叉树是否相同
void insertNode(Node* root,char c){
    Node *tmp=root,*before=NULL;
    int flag=0;
    while(tmp){
        before=tmp;
        if(c<tmp->element){
            tmp=tmp->lc;
            flag=1;
        }
        else if(c>tmp->element){
            tmp=tmp->rc;
            flag=2;
        }
        else break;
    }
    if(!tmp){
        tmp=new Node();
        tmp->element=c;
        if(flag==1) before->lc=tmp;
        else if(flag==2) before->rc=tmp;
    }
}

void preOrder(Node* root,string &s){
    if(root){
        s+=root->element;
        preOrder(root->lc,s);
        preOrder(root->rc,s);
    }
}

void inOrder(Node* root,string &s){
    if(root){
        inOrder(root->lc,s);
        s+=root->element;
        inOrder(root->rc,s);
    }
}

int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        string s,pre,in;
        cin>>s;
        int len=s.size();
        Node *root=new Node();
        root->element=s[0];
        for(int i=1;i<len;i++) insertNode(root,s[i]);
        preOrder(root,pre);
        inOrder(root,in);
        for(int i=0;i<n;i++){
            string com_pre,com_in;
            cin>>s;
            len=s.size();
            root=new Node();
            root->element=s[0];
            for(int i=1;i<len;i++) insertNode(root,s[i]);
            preOrder(root,com_pre);
            inOrder(root,com_in);
            if(pre==com_pre&&in==com_in)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}
