/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }

        Node* first = root;// 每层的起始节点
        while (first->left) {
            Node* p = first;// 对每层的各节点进行遍历
            while (p) {
                p->left->next = p->right;
                if (p->next) {
                    p->right->next = p->next->left;
                }
                p = p->next;
            }
            first = first->left;
        }

        return root;
    }
};