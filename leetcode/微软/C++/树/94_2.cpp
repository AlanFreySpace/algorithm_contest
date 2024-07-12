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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sk;
        vector<int> ans;

        while (root || !sk.empty()) {
            while (root) {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            ans.push_back(root->val);

            root = root->right;
        }

        return ans;
    }
};