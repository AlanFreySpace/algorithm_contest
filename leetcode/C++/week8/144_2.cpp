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
        stack<TreeNode*> stk;
        if (!root) {
            return ans;
        }

        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                ans.push_back(root->val);
                root = root->left;
            }
            root = stk.top()->right;
            stk.pop();
        }

        return ans;
    }
};