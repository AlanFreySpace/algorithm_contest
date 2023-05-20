package week6;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class p94_3 {
	public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans=new ArrayList<>();
        Stack<TreeNode> sk=new Stack<>();
        
        /**
         * root:当前遍历子树的根节点
         * sk:用于保存还未进行取值的节点     
         */
        while(root!=null||!sk.empty()){
            while(root!=null){//1.不断向左压入子树根节点
                sk.push(root);
                root=root.left;
            }
            root=sk.peek();
            sk.pop();
            ans.add(root.val);//2.得到中间节点的值
            root=root.right;//3.转向中间节点的右侧
        }

        return ans;
    }
}
