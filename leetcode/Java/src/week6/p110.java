package week6;

public class p110 {
	boolean ans = true;

    public boolean isBalanced(TreeNode root) {
        if(root == null) {
            return true;
        }
        getHeight(root);
        return ans;
    }

    // 注意测试例:[1,2,2,3,null,null,3,4,null,null,4]
    int getHeight(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int lh = getHeight(root.left);
        int rh = getHeight(root.right);
        if(Math.abs(lh - rh) > 1) { // 注意:应判断每颗子树是否平衡
            ans = false;
        }
        return Math.max(lh, rh) + 1;
    }
}
