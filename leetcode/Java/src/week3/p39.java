package week3;

import java.util.ArrayList;
import java.util.List;

public class p39 {
	List<List<Integer>> ans=new ArrayList<>();
    List<Integer> path=new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] arr, int target) {
        dfs(arr,0,target);
        return ans;
    }

    void dfs(int[] arr,int u,int target){
        if(target==0){
        	/*
        	 * 此处注意,一定要new一个新的ArrayList,如果写ans.add(path);
        	 * 则ans中添加的每一项都是指向path的一个指针,由于path.remove
        	 * 这一句，ans最终将被插入一堆空列表
        	 */
            ans.add(new ArrayList(path));
            return;
        }
        if(u==arr.length) return;

        for(int i=0;i*arr[u]<=target;i++){
            dfs(arr,u+1,target-i*arr[u]);
            path.add(arr[u]);
        }

        for(int i=0;i*arr[u]<=target;i++) path.remove(path.size()-1);
    }
}
