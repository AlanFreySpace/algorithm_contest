/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
 //方法一:额外空间O(n) 时间O(n)
class Solution {
public:
    vector<int> nums;

    TreeNode* sortedListToBST(ListNode* head) {
        for(auto p=head;p;p=p->next) nums.push_back(p->val);
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

//方法二:时间复杂度O(n) 空间只有递归栈的O(log n)
class Solution {
public:
    ListNode* cur;

    TreeNode* sortedListToBST(ListNode* head) {
        cur=head;
        int n=0;
        for(auto p=cur;p;p=p->next) n++;
        return build(0,n-1);
    }

    TreeNode* build(int l,int r){
        if(l>r) return nullptr;
        int mid=(l+r)>>1;
        auto root=new TreeNode();
        root->left=build(l,mid-1);
        root->val=cur->val;
        cur=cur->next;
        root->right=build(mid+1,r);
        return root;
    }
};
