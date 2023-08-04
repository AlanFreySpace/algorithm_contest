package week6;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class p102 {
	public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();

        if(root != null) {
            queue.offer(root);
        }

        while(queue.size() != 0) {
            List<Integer> tmp = new ArrayList<>();

            Integer len = queue.size();
            while(len-- != 0) {
                TreeNode now = queue.poll();
                tmp.add(now.val);
                if(now.left != null) {
                    queue.offer(now.left);
                }
                if(now.right != null) {
                    queue.offer(now.right);
                }
            }

            ans.add(tmp);
        }

        return ans;
    }
}
