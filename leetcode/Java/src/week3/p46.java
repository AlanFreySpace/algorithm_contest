package week3;

import java.util.ArrayList;
import java.util.List;

public class p46 {
	List<List<Integer>> ans=new ArrayList<>();
    List<Integer> path=new ArrayList<>();
    boolean[] flag;

    public List<List<Integer>> permute(int[] nums) {
        int n=nums.length;
        flag=new boolean[n];
        dfs(nums,n,0);
        return ans;
    }

    void dfs(int[] nums,int n,int index){
        if(index==n) ans.add(new ArrayList(path));
        for(int i=0;i<n;i++){
            if(!flag[i]){
                path.add(nums[i]);
                flag[i]=true;
                dfs(nums,n,index+1);
                path.remove(index);
                flag[i]=false;
            }
        }
    }
}
