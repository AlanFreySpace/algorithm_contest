class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        dfs(c,0,target);
        return ans;
    }

    void dfs(vector<int>& c,int u,int target){
        if(target==0){
            ans.push_back(path);
            return;
        }
        if(u==c.size()) return;

        int k=u+1;
        while(k<c.size()&&c[u]==c[k]) k++;
        int cnt=k-u;//c[u]的最大出现次数

        for(int i=0;i*c[u]<=target&&i<=cnt;i++){
            dfs(c,k,target-i*c[u]);
            path.push_back(c[u]);
        }

        for(int i=0;i*c[u]<=target&&i<=cnt;i++){
            path.pop_back();
        }
    }
};
