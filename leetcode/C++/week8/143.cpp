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
    void reorderList(ListNode* head) {
        // 1.计算链表长度
        ListNode* cur = head;
        int size = 0;
        while (cur) {
            size++;
            cur = cur->next;
        }

        // 2.从中间将链表拆分成两段
        ListNode* firstTail = head, * secondHead = NULL;
        for (int i = 0; i < size / 2; i++) {
            firstTail = firstTail->next;
        }
        secondHead = firstTail->next;
        firstTail->next = NULL;

        // 3.反转第二段链表
        ListNode* before = NULL, * after = secondHead;
        while (after) {
            ListNode* tmp = after->next;
            after->next = before;
            before = after;
            after = tmp;
        }
        secondHead = before;

        // 4.将第二段链表插入到第一段链表
        ListNode* firstCur = head, * secondCur = secondHead;
        while (firstCur && secondCur) {
            ListNode* tmp = firstCur->next, * tmp2 = secondCur->next;
            firstCur->next = secondCur;
            secondCur->next = tmp;
            firstCur = tmp;
            secondCur = tmp2;
        }
    }
};