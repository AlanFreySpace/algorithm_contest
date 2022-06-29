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
 //O(n)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0,nums.size()-1,nums);
    }

    TreeNode* build(int l,int r,vector<int>& nums){
        if(l>r) return nullptr;
        int mid=(l+r)>>1;
        auto root=new TreeNode(nums[mid]);
        root->left=build(l,mid-1,nums);
        root->right=build(mid+1,r,nums);
        return root;
    }
};
