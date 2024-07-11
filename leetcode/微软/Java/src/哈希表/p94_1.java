package ¹þÏ£±í;

import java.util.ArrayList;
import java.util.List;

// µÝ¹é½â·¨
public class p94_1 {
	List<Integer> ans = new ArrayList<>();

    public List<Integer> inorderTraversal(TreeNode root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode root) {
        if(root == null) return;
        inorder(root.left);
        ans.add(root.val);
        inorder(root.right);
    }
}
