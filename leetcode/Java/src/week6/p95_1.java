package week6;

import java.util.ArrayList;
import java.util.List;

public class p95_1 {
	// 未进行记忆化搜索和垃圾回收的版本
	public List<TreeNode> generateTrees(int n) {
        return dfs(1,n);
    }

	// 生成元素为[left,right]的二叉搜索树，若引入记忆化搜索可优化时间复杂度，若引入垃圾回收
	// 可降低空间复杂度
    List<TreeNode> dfs(int left,int right){
        List<TreeNode> ans=new ArrayList<>();
        if(left>right){
            ans.add(null);// 注意这步是必要的
            return ans;
        }

        for(int i=left;i<=right;i++){
            List<TreeNode> left_roots=dfs(left,i-1),right_roots=dfs(i+1,right);
            for(TreeNode lr:left_roots){
                for(TreeNode rr:right_roots){
                    TreeNode root=new TreeNode(i);
                    root.left=lr;
                    root.right=rr;
                    ans.add(root);
                }
            }
        }

        return ans;
    }
}
