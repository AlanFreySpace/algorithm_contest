package week6;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class p94_2 {
	public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans=new ArrayList<>();
        Stack<TreeNode> sk=new Stack<>();

        if(root!=null) sk.push(root);
        else return ans;

        TreeNode cur=null;
        while(!sk.empty()){
            while(sk.peek().left!=null){
                cur=
            }
        }
    }
}
