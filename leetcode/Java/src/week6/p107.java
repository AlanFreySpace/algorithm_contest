package week6;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class p107 {
	public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        List<List<Integer>> ans = new ArrayList<>();

        if(root != null) {
            queue.offer(root);
        }

        while(queue.size() != 0) {
            List<Integer> tmp = new ArrayList<>();
            Integer length = queue.size();

            while(length-- != 0) {
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

        Collections.reverse(ans);
        return ans;
    }
}
