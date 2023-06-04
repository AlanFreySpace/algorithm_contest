package week6;

public class p98_2 {
	public boolean isValidBST(TreeNode root) {
        return dfs(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }

    boolean dfs(TreeNode root,long minNum,long maxNum){
        if(root==null) return true;
        if(root.val<=minNum||root.val>=maxNum) return false;
        return dfs(root.left,minNum,root.val)&&dfs(root.right,root.val,maxNum);
    }
}
