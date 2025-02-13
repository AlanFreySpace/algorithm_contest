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
        if (!head) {
            return NULL;
        }

        auto cur = head;

        while (cur) { // 复制一个小弟
            auto tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        cur = head;
        auto ans = head->next;

        while (cur) { // 复制random指针
            auto newCur = cur->next;
            if (cur->random) {
                newCur->random = cur->random->next;
            }
            cur = newCur->next;
        }

        cur = head;
        while (cur) { // 拆分两个链表
            auto newCur = cur->next, oriNext = newCur->next;
            cur->next = oriNext;
            if (oriNext) {
                newCur->next = oriNext->next;
            }
            cur = oriNext;
        }

        return ans;
    }
};