package week6;

import java.util.ArrayList;
import java.util.List;

public class p94_1 {
	// 递归解法 空间复杂度高
	List<Integer> ans=new ArrayList<>();

    public List<Integer> inorderTraversal(TreeNode root) {
        inOrder(root);
        return ans;
    }

    void inOrder(TreeNode root){
        if(root==null) return;
        if(root.left!=null) inOrder(root.left);
        ans.add(root.val);
        if(root.right!=null) inOrder(root.right); 
    }
}
