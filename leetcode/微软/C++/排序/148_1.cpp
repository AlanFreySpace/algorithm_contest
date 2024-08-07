class Solution {
public:
    // 自底向上非递归形式的归并排序算法
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) {
            n++;
        }

        /**
        * i.将两段长度为i的有序序列合并为一段有序序列。
        * ii.注意变量j的作用：从第j个元素开始对序列进行排序，
        * 此时需要判断j+i<=n，确保有第二段有序序列，否则
        * 只有一段有序序列，此时序列自然有序，无需进入循环
        * 将两段有序序列合并为一段。
        * iii.注意变量cur,p,q的作用：p是第一段有序序列的指针，
        * q是第二段有序序列的指针，cur是前驱节点，若p->val<=q->val，
        * 前驱节点cur应该指向p，并更新cur为p，将p向前移动，p=p->next,
        * 当p->val>q.val时同理。
        */
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
                // 此处其实无需判断p是否为空，因为上面j+i<=n确保了第一段有序序列长度为i，
                // 在l<i时p必然不为空
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

                // 此处无需判断p是否为空，因为上面j+i<=n确保了第一段有序序列长度为i，
                // 在l<i时p必然不为空
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

                // 以上循环结束后，q将指向下一段要归并序列的头结点，应将cur->next指向该节点
                cur->next = q;
            }
        }

        return dummy->next;
    }
};