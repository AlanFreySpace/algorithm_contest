package week6;

public class p100 {
	public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null||q==null){
            if(p!=null||q!=null) return false;
            return true;
        }

        if(p.val==q.val){
            return isSameTree(p.left,q.left)&&isSameTree(p.right,q.right);
        }
        return false;
    }
}
