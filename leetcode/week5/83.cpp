/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto p=head;//第一个指针
        while(p){
            auto q=p->next;//第二个指针
            while(q&&p->val==q->val) q=q->next;
            if(q==p->next) p=p->next;
            else p=p->next=q;
        }
        return head;
    }
};
