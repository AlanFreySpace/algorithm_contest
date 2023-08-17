package week7;

import week6.TreeNode;

public class p112_1 {
	// 该递归写的太麻烦,注意怎么简单写
	public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) {
            return false;
        }
        return dfs(root, targetSum, root.val);
    }

    public boolean dfs(TreeNode root, int targetSum, int sumNow) {
        if(root.left == null && root.right == null) {
            return targetSum == sumNow;
        }
        if(root.left == null) {
            return dfs(root.right, targetSum, sumNow + root.right.val);
        }
        if(root.right == null) {
            return dfs(root.left, targetSum, sumNow + root.left.val);
        }
        boolean leftRes = dfs(root.left, targetSum, sumNow + root.left.val);
        boolean rightRes = dfs(root.right, targetSum, sumNow + root.right.val);
        return leftRes || rightRes;
    }
}
