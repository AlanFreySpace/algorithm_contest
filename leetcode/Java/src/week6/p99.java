package week6;

public class p99 {
	public void recoverTree(TreeNode root) {
        TreeNode first = null, second = null, last = null;

        while(root != null) {
            if(root.left == null) {
                if(last != null && last.val > root.val) {
                    if(first == null) {
                        first = last;
                        second = root;
                    }
                    else {
                        second = root;
                    }
                }

                last = root;
                root = root.right;
            }
            else {
                TreeNode p = root.left;
                while(p.right != null && p.right != root) {
                    p = p.right;
                }

                if(p.right == null) {
                    p.right = root;
                    root = root.left;
                }
                else {
                    p.right = null;

                    if(last != null && last.val > root.val) {
                        if(first == null) {
                            first = last;
                            second = root;
                        }
                        else {
                            second = root;
                        }
                    }

                    last = root;
                    root = root.right;
                }
            }
        }

        int tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }
}
