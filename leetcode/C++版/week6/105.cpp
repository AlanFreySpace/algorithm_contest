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
class Solution {//时间复杂度O(n)
public:
    unordered_map<int,int> pos;//哈希表查找中序遍历中根节点的位置

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) pos[inorder[i]]=i;
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int pl,int pr,int il,int ir){
        if(pl>pr) return NULL;//注意此处应返回
        auto root=new TreeNode(preorder[pl]);
        int k=pos[preorder[pl]];
        root->left=build(preorder,inorder,pl+1,k-il+pl,il,k-1);//构建左子树
        root->right=build(preorder,inorder,k-il+pl+1,pr,k+1,ir);//构建右子树
        return root;
    }
};
