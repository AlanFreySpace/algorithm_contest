package week6;

public class p98_1 {
	int before;
    boolean first=true,ans=true;

    /**
     * 方法一:
     * 利用二叉搜索树的性质:
     * 若二叉树是二叉搜索树，则其中序遍历是升序序列
     * 代码里体现的是逆否命题：
     * 若二叉树的中序遍历不是升序序列，则该二叉树不是二叉搜索树
     */
    public boolean isValidBST(TreeNode root) {
        inOrder(root);
        return ans;
    }

    void inOrder(TreeNode root){
        if(root==null) return;

        if(root.left!=null) inOrder(root.left);
        if(first){
            before=root.val;
            first=false;
        }else{
            if(root.val<=before){
                ans=false;
                return;
            }else{
                before=root.val;
            }
        }
        if(root.right!=null) inOrder(root.right);
    }
}
