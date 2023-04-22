package week5;

import java.util.ArrayList;
import java.util.List;

public class p78 {
	List<Integer> path=new ArrayList<Integer>();
    List<List<Integer>> ans=new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums) {
        int n=nums.length;
        for(int i=0;i<=n;i++){
            dfs(nums,n,i,0);
        }
        return ans;
    }

    /**
     * 其实与77题是同一题,只需对不同的k进行dfs遍历即可
     * @param nums
     * @param n nums[]中的元素总数
     * @param k 要排的元素数量
     * @param index 起始元素位置
     */
    void dfs(int[] nums,int n,int k,int index){
        if(k==0){
            ans.add(new ArrayList(path));
            return;
        }
        for(int i=index;i<=n-k;i++){
            path.add(nums[i]);
            dfs(nums,n,k-1,i+1);
            path.remove(path.size()-1);
        }
    }
}
