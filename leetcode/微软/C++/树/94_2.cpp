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
// 方法二：利用栈进行迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sk;
        vector<int> ans;

        while (root || !sk.empty()) { // stack为空且root为null时，说明已经遍历结束
            while (root) { // 可以深入左孩子
                sk.push(root);
                root = root->left;
            }
            // 否则访问栈中节点，并深入右孩子
            root = sk.top();
            sk.pop();
            ans.push_back(root->val);

            root = root->right;
        }

        return ans;
    }
};