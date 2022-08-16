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
    void recoverTree(TreeNode* root) {
        //first second记录应交换的节点 last记录上一个遍历的节点
        TreeNode *first=NULL,*second=NULL,*last=NULL;
        while(root){
            if(!root->left){//无左子树
                if(last&&last->val>root->val){
                    if(!first) first=last,second=root;
                    else second=root;
                }
                last=root;
                root=root->right;
            }else{//有左子树
                auto p=root->left;
                //p->right!=root是为了排除回溯的那条边造成死循环
                while(p->right&&p->right!=root) p=p->right;//找前驱节点
                if(!p->right) p->right=root,root=root->left;//前驱节点未遍历
                else{//前驱节点已遍历
                    p->right=NULL;
                    if(last&&last->val>root->val){
                        if(!first) first=last,second=root;
                        else second=root;
                    }
                    last=root;
                    root=root->right;
                }
            }
        }
        swap(first->val,second->val);
    }
};
