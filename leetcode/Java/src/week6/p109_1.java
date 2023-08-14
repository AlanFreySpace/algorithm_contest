package week6;

import java.util.ArrayList;
import java.util.List;

import week1.ListNode;

public class p109_1 {
	List<Integer> nums = new ArrayList<>();

    public TreeNode sortedListToBST(ListNode head) {
        ListNode cur = head;
        while(cur != null) {
            nums.add(cur.val);
            cur = cur.next;
        }

        return build(nums, 0, nums.size() - 1);
    }

    TreeNode build(List<Integer> nums, int left, int right) {
        if(left > right) {
            return null;
        }

        int mid = (left + right) >> 1;
        TreeNode root = new TreeNode(nums.get(mid));
        root.left = build(nums, left, mid - 1);
        root.right = build(nums, mid + 1, right);

        return root;
    }
}
