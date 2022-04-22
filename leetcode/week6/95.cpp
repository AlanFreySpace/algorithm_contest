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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1,n);
    }

    vector<TreeNode*> dfs(int left,int right){
        if(left>right) return {NULL};//注意该递归基,left==right时的下一步
        vector<TreeNode*> ans;
        for(int i=left;i<=right;i++){
            auto le=dfs(left,i-1),ri=dfs(i+1,right);
            for(auto l:le){
                for(auto r:ri){
                    auto node=new TreeNode(i);
                    node->left=l,node->right=r;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
};
