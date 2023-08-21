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
        Node* p = root;
        while (p) {
            /*
            dummy: 当前正在遍历层级的哨兵节点
            tail: 遍历到的尾节点
            */
            Node* dummy = new Node(), * tail = dummy;
            while (p) {
                if (p->left) {
                    tail->next = p->left;
                    tail = p->left;
                }
                if (p->right) {
                    tail->next = p->right;
                    tail = p->right;
                }
                p = p->next;
            }
            p = dummy->next;
        }
        return root;
    }
};