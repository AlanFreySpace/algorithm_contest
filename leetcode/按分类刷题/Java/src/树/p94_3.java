package 树;

import java.util.ArrayList;
import java.util.List;

public class p94_3 {
	public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();

        while(root != null) {
            if(root.left == null) {
                ans.add(root.val);
                root = root.right;
            } else {
                TreeNode pre = root.left;
                while(pre.right!=null && pre.right != root) {
                    pre = pre.right;
                }
                if(pre.right == root) {
                    pre.right = null;
                    ans.add(root.val);
                    root = root.right;
                } else {
                    pre.right = root;
                    root = root.left;
                }
            }
        }

        return ans;
    }
}
