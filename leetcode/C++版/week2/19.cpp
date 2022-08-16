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
    ListNode* removeNthFromEnd(ListNode* head, int n) {//快慢指针复杂度实际上和这个
        auto dummy=new ListNode(-1);//做法复杂度相同
        dummy->next=head;

        int num=0;
        for(auto p=dummy;p;p=p->next) num++;

        auto p=dummy;
        for(int i=0;i<num-n-1;i++) p=p->next;
        p->next=p->next->next;
        return dummy->next;
    }
};
