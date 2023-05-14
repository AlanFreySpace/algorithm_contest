package week5;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p90 {
	List<Integer> path=new ArrayList<>();
    List<List<Integer>> ans=new ArrayList<>();

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        dfs(nums,0,nums.length);
        return ans;
    }

    void dfs(int[] nums,int from,int n){
        ans.add(new ArrayList(path));

        for(int i=from;i<n;i++){
            path.add(nums[i]);
            dfs(nums,i+1,n);
            while(i<n-1&&nums[i]==nums[i+1]) i++;
            path.remove(path.size()-1);
        }
    }
}
