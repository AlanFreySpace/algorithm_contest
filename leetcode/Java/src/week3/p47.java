package week3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p47 {
	List<List<Integer>> ans=new ArrayList<>();
    List<Integer> path=new ArrayList<>();
    boolean[] flag;
    int n;

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        n=nums.length;
        flag=new boolean[n];
        dfs(nums,n,0);
        return ans;
    }

    /*
     * 可以用[1,1,2]这个样例模拟,加深理解
     */
    void dfs(int[] nums,int n,int index){
        if(index==n) ans.add(new ArrayList(path));

        for(int i=0;i<n;){
            if(!flag[i]){
                path.add(nums[i]);
                flag[i]=true;
                dfs(nums,n,index+1);
                flag[i]=false;
                path.remove(index);
                int k=i+1;//避免某位置重复填某一元素
                while(k<n&&nums[k]==nums[i]) k++;
                i=k;
            }else i++;
        }
    }
}
