package week6;

import java.util.ArrayList;
import java.util.List;

public class p95_2 {
	List<TreeNode>[][] memo;

	public List<TreeNode> generateTrees(int n) {
        memo=new List[n+1][n+1];// 加入记忆化搜索 注意如何声明List数组
        //memo=(List<TreeNode>[][])new List[n+1][n+1]; 这种写法也行
        //memo=new List<TreeNode>[n+1][n+1]; 这种写法是不允许的
        System.gc();//引入垃圾回收
        return dfs(1,n);
    }

    List<TreeNode> dfs(int left,int right){
        List<TreeNode> ans=new ArrayList<>();
        if(left>right){
            ans.add(null);
            return ans;
        }

        if(memo[left][right]!=null) return memo[left][right];

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
        
        memo[left][right]=ans;
        return ans;
    }
}
