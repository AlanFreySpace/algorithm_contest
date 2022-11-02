package week3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p40 {
	List<List<Integer>> ans=new ArrayList<>();
    List<Integer> path=new ArrayList<>();

    public List<List<Integer>> combinationSum2(int[] arr, int target) {
        Arrays.sort(arr);
        dfs(arr,0,target);
        return ans;
    }

    void dfs(int[] arr,int u,int target){
        if(target==0){
            ans.add(new ArrayList(path));
            return;
        }
        if(u==arr.length) return;
        //注意这段逻辑很巧妙
        int k=u+1;
        while(k<arr.length&&arr[u]==arr[k]) k++;
        int cnt=k-u;

        for(int i=0;i*arr[u]<=target&&i<=cnt;i++){
            dfs(arr,k,target-i*arr[u]);
            path.add(arr[u]);
        }

        for(int i=0;i*arr[u]<=target&&i<=cnt;i++) path.remove(path.size()-1);
    }
}
