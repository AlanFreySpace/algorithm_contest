package week6;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class p94_3 {
	public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans=new ArrayList<>();
        Stack<TreeNode> sk=new Stack<>();
        
        while(root!=null||!sk.empty()){
            while(root!=null){
                sk.push(root);
                root=root.left;
            }
            root=sk.peek();
            sk.pop();
            ans.add(root.val);
            root=root.right;
        }

        return ans;
    }
}
