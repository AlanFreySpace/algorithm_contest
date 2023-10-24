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
/**
* 方法一:采用恢复现场的写法
*/
class Solution {
public:
    int ans = 0, path = 0;

    int sumNumbers(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        path = path * 10 + root->val;
        if (!root->left && !root->right) {
            ans += path;
            return;
        }
        if (root->left) {
            dfs(root->left);
            path = (path - root->left->val) / 10;
        }
        if (root->right) {
            dfs(root->right);
            path = (path - root->right->val) / 10;
        }
    }
};