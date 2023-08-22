/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        // 若左子树或右子树的贡献为负 则不向左子树或右子树走 即为0
        int l = max(0, dfs(root->left)), r = max(0, dfs(root->right));
        ans = max(ans, l + root->val + r);
        return root->val + max(l, r);
    }
};