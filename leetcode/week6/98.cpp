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
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }

    bool dfs(TreeNode* root,long minNum,long maxNum){
        if(!root) return true;
        if(root->val<=minNum||root->val>=maxNum) return false;
        //向左上界变小 向右下界变大
        return dfs(root->left,minNum,root->val)&&dfs(root->right,root->val,maxNum);
    }
};
