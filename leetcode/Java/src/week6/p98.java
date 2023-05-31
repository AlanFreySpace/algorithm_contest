package week6;

public class p98 {
	int before;
    boolean first=true,ans=true;

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
