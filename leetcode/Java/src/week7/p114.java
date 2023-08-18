package week7;

import week6.TreeNode;

public class p114 {
	public void flatten(TreeNode root) {
        while(root != null) {
            TreeNode p = root.left;
            if(p != null) {
                while(p.right != null) {
                    p = p.right;
                }
                p.right = root.right;
                root.right = root.left;
                root.left = null;
            }
            root = root.right;
        }
    }
}
