#include <iostream>
using namespace std;

struct Node {
    char element;
    Node* lc=NULL, * rc = NULL;
};
//ע��˴�Ӧ����&����ָ������,����ֻ�Ǹı��β�
void createTree(Node* &root) {
    char tmp;
    cin >> tmp;//ע����cin�����ַ�,���ÿո�ָ�,scanf�Ὣ�ո�ͻس��������ַ�
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
