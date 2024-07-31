class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) {
            n++;
        }

        auto dummy = new ListNode(-1);
        dummy->next = head;
        for (int i = 1; i < n; i *= 2) {
            auto cur = dummy;
            for (int j = 1; j + i <= n; j += 2 * i) {
                auto p = cur->next, q = p;
                for (int k = 0; k < i; k++) {
                    q = q->next;
                }

                int l = 0, r = 0;
                while (l < i && r < i && p && q) {
                    if (p->val <= q->val) {
                        cur->next = p;
                        cur = p;
                        p = p->next;
                        l++;
                    }
                    else {
                        cur->next = q;
                        cur = q;
                        q = q->next;
                        r++;
                    }
                }

                while (l < i) {
                    cur->next = p;
                    cur = p;
                    p = p->next;
                    l++;
                }
                while (q && r < i) {
                    cur->next = q;
                    cur = q;
                    q = q->next;
                    r++;
                }

                cur->next = q;
            }
        }

        return dummy->next;
    }
};