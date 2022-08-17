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
    unordered_map<int,int> pos;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) pos[inorder[i]]=i;
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int il,int ir,int pl,int pr){
        if(il>ir) return NULL;
        auto root=new TreeNode(postorder[pr]);
        int k=pos[postorder[pr]];
        root->left=build(inorder,postorder,il,k-1,pl,k-1-il+pl);
        root->right=build(inorder,postorder,k+1,ir,k-il+pl,pr-1);
        return root;
    }
};
