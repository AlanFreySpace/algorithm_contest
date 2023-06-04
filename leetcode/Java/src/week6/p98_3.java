package week6;

import java.util.Stack;

public class p98_3 {
	public boolean isValidBST(TreeNode root) {
        long before=Long.MIN_VALUE;
        Stack<TreeNode> sk=new Stack<>();
        while(root!=null||!sk.empty()){
            while(root!=null){
                sk.push(root);
                root=root.left;
            }
            root=sk.peek();
            sk.pop();
            if(root.val<=before) return false;
            before=root.val;
            root=root.right;
        }
        return true;
    }
}
