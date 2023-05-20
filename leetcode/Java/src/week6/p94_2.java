package week6;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class p94_2 {
	// 这种迭代方式会破坏原树的结构 不推荐
	public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans=new ArrayList<>();
        Stack<TreeNode> sk=new Stack<>();

        if(root!=null) sk.push(root);
        
        while(!sk.empty()){
            while(sk.peek().left!=null){
                TreeNode tmp=sk.peek().left;
                sk.peek().left=null;
                sk.push(tmp);
            }
            TreeNode cur=sk.peek();
            System.out.println(cur.val);
            ans.add(cur.val);
            sk.pop();
            if(cur.right!=null){
                sk.push(cur.right);
            }
        }

        return ans;
    }
}
