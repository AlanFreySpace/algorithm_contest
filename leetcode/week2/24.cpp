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
    ListNode* swapPairs(ListNode* head) {
        auto dummy=new ListNode(-1);
        dummy->next=head;

        for(auto p=dummy;p->next&&p->next->next;){//利用三个指针解决问题
            auto a=p->next,b=p->next->next;
            //此处注意顺序
            p->next=b;
            a->next=b->next;
            b->next=a;
            p=a;
        }
        return dummy->next;
    }
};
