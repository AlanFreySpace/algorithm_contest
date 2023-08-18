class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }

        Node* first = root;// ÿ�����ʼ�ڵ�
        while (first->left) {
            Node* p = first;// ��ÿ��ĸ��ڵ���б���
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