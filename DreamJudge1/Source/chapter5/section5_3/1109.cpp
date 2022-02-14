#include <iostream>
using namespace std;

struct Node {
    char element;
    Node* lc=NULL, * rc = NULL;
};
//注意此处应该用&传递指针引用,否则只是改变形参
void createTree(Node* &root) {
    char tmp;
    cin >> tmp;//注意用cin读入字符,其用空格分割,scanf会将空格和回车都当作字符
    if (tmp != '0') {
        root = new Node();
        root->element = tmp;
        createTree(root->lc);
        createTree(root->rc);
    }
}

void PreOrder(Node* root) {
    if (root) {
        cout<<root->element<<" ";
        PreOrder(root->lc);
        PreOrder(root->rc);
    }
}

void InOrder(Node* root) {
    if (root) {
        InOrder(root->lc);
        cout<<root->element<<" ";
        InOrder(root->rc);
    }
}

void PostOrder(Node* root) {
    if (root) {
        PostOrder(root->lc);
        PostOrder(root->rc);
        cout<<root->element<<" ";
    }
}

int leaf(Node* root){
    if(!root) return 0;
    if(!root->lc&&!root->rc) return 1;
    return leaf(root->lc)+leaf(root->rc);
}

int main() {
    Node* root = NULL;
    createTree(root);
    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    int ans=leaf(root);
    cout<<ans;
    return 0;
}
