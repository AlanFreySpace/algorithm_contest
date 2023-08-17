package week7;

import week6.TreeNode;

public class p111 {
	public int minDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }

        int ld = minDepth(root.left);
        int rd = minDepth(root.right);

        if(ld == 0 && rd == 0) {
            return 1;
        }
        if(ld == 0) {
            return rd + 1;
        }
        if(rd == 0) {
            return ld + 1;
        }
        return Math.min(ld, rd) + 1;
    }
}
