package week5;

import java.util.ArrayList;
import java.util.List;

public class p90 {
	List<Integer> path=new ArrayList<>();
    List<List<Integer>> ans=new ArrayList<>();

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        dfs(nums,0,nums.length);
        return ans;
    }

    void dfs(int[] nums,int from,int n){
        if(from==n) return;
        ans.add(new ArrayList(path));

        for(int i=from;i<n;i++){
            path.add(nums[i]);
            dfs(nums,i+1,n);
            path.remove(path.size()-1);
        }
    }
}
