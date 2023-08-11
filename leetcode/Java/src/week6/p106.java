package week6;

import java.util.HashMap;

public class p106 {
	HashMap<Integer, Integer> hash = new HashMap<>();

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        for(int i = 0; i < inorder.length; i++) {
            hash.put(inorder[i], i);
        }
        return build(inorder, postorder, 0, inorder.length - 1, 0, inorder.length - 1);
    }

    TreeNode build(int[] inorder, int[] postorder, int il, int ir, int pl, int pr) {
        if(il > ir) {
            return null;
        }

        TreeNode root = new TreeNode(postorder[pr]);
        Integer index = hash.get(postorder[pr]);
        root.left = build(inorder, postorder, il, index - 1, pl, pl + index - il - 1);
        root.right = build(inorder, postorder, index + 1, ir, pl + index - il, pr - 1);
        return root;
    }
}
