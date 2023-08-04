package week6;

import java.util.HashMap;

public class p105 {
	HashMap<Integer, Integer> hash = new HashMap<>();

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        for(int i = 0; i < inorder.length; i++) {
            hash.put(inorder[i], i);
        }
        return build(preorder, inorder, 0, preorder.length - 1, 0, inorder.length - 1);
    }

    TreeNode build(int[] preorder, int[] inorder, int pl, int pr, int il, int ir) {
        if(pl > pr) {
            return null;
        }

        TreeNode root = new TreeNode(preorder[pl]);
        int pos = hash.get(preorder[pl]);

        root.left = build(preorder, inorder, pl + 1, pl + pos - il, il, pos - 1);
        root.right = build(preorder, inorder, pl + pos - il + 1, pr, pos + 1, ir);

        return root;
    }
}
