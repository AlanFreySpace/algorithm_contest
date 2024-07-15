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
        vector<int> ans;

        while (root) {
            // 如果没有左孩子，则直接访问右孩子
            if (!root->left) {
                ans.push_back(root->val);
                root = root->right;
            }
            else {
                // pre节点就是当前root节点向左走一步，然后一直向右走至无法走为止
                auto pre = root->left;
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                if (pre->right) {
                    ans.push_back(root->val);
                    root = root->right;
                    pre->right = NULL;
                }
                else { // 让pre的右指针指向root，继续遍历左子树
                    pre->right = root;
                    root = root->left;
                }
            }
        }

        return ans;
    }
};