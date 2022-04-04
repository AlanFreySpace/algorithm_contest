class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        dfs(n,k,1);
        return ans;
    }

    void dfs(int n,int k,int start){//从start开始,选取k个数字
        if(!k){
            ans.push_back(path);
            return;
        }

        for(int i=start;i<=n;i++){//start不能越界
            path.push_back(i);
            dfs(n,k-1,i+1);
            path.pop_back();
        }
    }
};
