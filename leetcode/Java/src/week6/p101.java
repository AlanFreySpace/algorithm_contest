package week6;

public class p101 {
	public boolean isSymmetric(TreeNode root) {
        return dfs(root.left,root.right);
    }

    boolean dfs(TreeNode left,TreeNode right){
        if(left==null&&right==null) return true;
        if(left==null||right==null||left.val!=right.val) return false;
        return dfs(left.left,right.right)&&dfs(left.right,right.left);
    }
}
