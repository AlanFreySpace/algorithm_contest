package 树;

import java.util.ArrayList;
import java.util.List;

import 树.TreeNode;


// 方法一:递归写法 空间复杂度O(n) 时间复杂度O(n) 思路简单
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
