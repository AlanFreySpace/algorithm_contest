package ¹þÏ£±í;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class p94_2 {
	public List<Integer> inorderTraversal(TreeNode root) {
        Stack<TreeNode> sk = new Stack<>();
        List<Integer> ans = new ArrayList<>();

        while(root != null || !sk.empty()) {
            while(root != null) {
                sk.push(root);
                root = root.left;
            }
            root = sk.peek();
            sk.pop();
            ans.add(root.val);

            root = root.right;
        }

        return ans;
    }
}
