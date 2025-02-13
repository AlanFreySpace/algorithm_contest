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

        unordered_map<Node*, Node*> hash;
        auto ans = new Node(head->val);
        hash[head] = ans;

        while (head->next) {
            if (hash.count(head->next) == 0) {
                hash[head->next] = new Node(head->next->val);
            }
            hash[head]->next = hash[head->next];

            if (head->random && hash.count(head->random) == 0) {
                hash[head->random] = new Node(head->random->val);
            }
            hash[head]->random = hash[head->random];

            head = head->next;
        }
        hash[head]->random = hash[head->random];

        return ans;
    }
};