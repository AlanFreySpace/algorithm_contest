package week6;

import week1.ListNode;

public class p109_2 {
	ListNode cur;

    public TreeNode sortedListToBST(ListNode head) {
        cur = head;
        int n = 0;
        while(head != null) {
            head = head.next;
            n++;
        }

        return build(0, n-1);
    }

    TreeNode build(int left, int right) {
        if(left > right) {
            return null;
        }

        int mid = (left + right) >> 1;
        TreeNode root = new TreeNode();
        root.left = build(left, mid - 1);
        root.val = cur.val;
        cur = cur.next;
        root.right = build(mid + 1, right);

        return root;
    }
}
