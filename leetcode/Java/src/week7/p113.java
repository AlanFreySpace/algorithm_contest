package week7;

import java.util.ArrayList;
import java.util.List;

import week6.TreeNode;

public class p113 {
	List<List<Integer>> ans = new ArrayList<>();
    List<Integer> path = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        buildPath(root, targetSum);
        return ans;
    }

    void buildPath(TreeNode root, int targetSum) {
        if(root == null) {
            return;
        }

        targetSum -= root.val;
        path.add(root.val);

        if(root.left == null && root.right == null) {
            if(targetSum == 0) {
                ans.add(new ArrayList<>(path));
            }
        } else {
            buildPath(root.left, targetSum);
            buildPath(root.right, targetSum);
        }

        path.remove(path.size() - 1);
    }
}
