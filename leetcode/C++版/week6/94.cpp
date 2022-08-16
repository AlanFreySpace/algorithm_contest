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
//方法一:递归写法 空间复杂度较高 但思路简单
class Solution {
public:
    vector<int> ans;

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
};

//方法二:迭代写法 注意该方法如何运作的
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;

        while(root||stk.size()){
            while(root){//将左侧节点不断压入
                stk.push(root);
                root=root->left;
            }

            root=stk.top();//得到中间节点
            stk.pop();
            ans.push_back(root->val);
            root=root->right;//转向右子树
        }
        return ans;
    }
};
