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
        auto dummy=new ListNode(-1,head);
        auto p=dummy;//第一个指针
        while(p->next){
            auto q=p->next->next;//第二个指针
            while(q&&p->next->val==q->val) q=q->next;
            if(q==p->next->next) p=p->next;
            else p->next=q;
        }
        return dummy->next;
    }
};
