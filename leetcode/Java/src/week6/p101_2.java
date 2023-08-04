package week6;

import java.util.Stack;

public class p101_2 {
	// 方法二:迭代
	public boolean isSymmetric(TreeNode root) {
        if(root == null) {
            return true;
        }

        TreeNode lc = root.left, rc = root.right;
        Stack<TreeNode> ls = new Stack<>(), rs = new Stack<>();

        while(lc != null || rc != null || ls.size() != 0) {
            while(lc != null && rc != null) {
                ls.push(lc);
                rs.push(rc);
                lc = lc.left;
                rc = rc.right;
            }

            if(lc != null || rc != null) {
                return false;
            }

            lc = ls.peek();
            rc = rs.peek();
            ls.pop();
            rs.pop();
            if(lc.val != rc.val) {
                return false;
            }

            lc = lc.right;
            rc = rc.left;
        }

        return true;
    }
}
