package week5;

import java.util.ArrayList;
import java.util.List;

public class p77 {
	List<Integer> path=new ArrayList<>();
    List<List<Integer>> ans=new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        dfs(n,k,1);
        return ans;
    }

    /**
     * @param n 元素总个数
     * @param k 还有几个元素要排
     * @param index 初始元素
     */
    void dfs(int n,int k,int index){
        if(k==0){
            ans.add(new ArrayList<Integer>(path));
            return;
        }
        for(int i=index;i<=n-k+1;i++){
            path.add(i);
            dfs(n,k-1,i+1);
            path.remove(path.size()-1);
        }
    }
}
