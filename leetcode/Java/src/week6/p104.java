package week6;

public class p104 {
	class Solution {
	    public int maxDepth(TreeNode root) {
	        if(root == null) {
	            return 0;
	        }
	        int leftDepth = maxDepth(root.left) + 1;
	        int rightDepth = maxDepth(root.right) +1;
	        return Math.max(leftDepth,rightDepth);
	    }
	}
}
