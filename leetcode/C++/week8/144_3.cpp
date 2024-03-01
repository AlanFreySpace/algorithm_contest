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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        while (root) {
            if (!root->left) {
                ans.push_back(root->val);
                root = root->right;
            }
            else {
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }
                if (pre->right) {
                    root = root->right;
                    pre->right = NULL;
                }
                else {
                    ans.push_back(root->val);
                    pre->right = root;
                    root = root->left;
                }
            }
        }

        return ans;
    }
};