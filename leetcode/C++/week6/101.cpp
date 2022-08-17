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
class Solution {//方法一 递归 O(n)
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left,root->right);
    }

    bool dfs(TreeNode* p,TreeNode* q){
        if(!p&&!q) return true;
        if(!p||!q||p->val!=q->val) return false;
        return dfs(p->left,q->right)&&dfs(p->right,q->left);
    }
};

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
/*
用栈模拟递归,对根节点的左子树,我们用中序遍历(左中右)
对根节点的右子树,我们用反中序遍历(右中左)
则两个子树互为镜像,当且仅当同时遍历两课子树时,对应节点的值相等
*/
class Solution {//方法二:迭代 O(n)
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode *lc=root->left,*rc=root->right;
        stack<TreeNode*> ls,rs;

        /*
        (采用归纳法的思想理解如下过程)
        注意外部while中的条件很巧妙,若外部的while可以进入,则:
        1.若lc和rc一个为null,一个不为null,则两树结构不同,会返回false
        2.若lc和rc均为null,则ls不为空,又之前的循环没有返回false,说明之前的
        节点结构上是对称的,则rs与ls中有相同数量的节点,不必担心rs是空的
        3.若lc和rc均不为null,可类似规约成上述两种情况
        */
        while(lc||rc||ls.size()){
            while(lc&&rc){
                ls.push(lc),rs.push(rc);
                lc=lc->left,rc=rc->right;
            }

            if(lc||rc) return false;//两树结构不同
            lc=ls.top(),rc=rs.top();
            ls.pop(),rs.pop();
            if(lc->val!=rc->val) return false;//树结构相同但对应点的值不同
            lc=lc->right,rc=rc->left;
        }

        return true;
    }
};
