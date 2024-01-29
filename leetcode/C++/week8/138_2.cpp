/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        for (auto p = head; p; p = p->next->next) {// 复制一个小弟
            auto q = new Node(p->val);
            q->next = p->next;
            p->next = q;
        }

        for (auto p = head; p; p = p->next->next) {// 复制random指针
            if (p->random) {
                p->next->random = p->random->next;
            }
        }

        auto dummy = new Node(-1), cur = dummy;
        for (auto p = head; p; p = p->next) {// 拆分两个链表
            auto q = p->next;
            p->next = q->next;
            cur->next = q;
            cur = q;
        }

        return dummy->next;
    }
};