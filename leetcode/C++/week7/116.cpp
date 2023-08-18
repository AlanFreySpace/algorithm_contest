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