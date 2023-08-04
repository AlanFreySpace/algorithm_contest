package week6;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class p103 {
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        Integer cnt = 0;

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

            if(cnt % 2 == 1) {
                Collections.reverse(tmp);//注意Java中将List反序的方法
            }
            ans.add(tmp);
            cnt++;
        }

        return ans;
    }
}
