//递归写法一
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int n;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return res;
    }

    void dfs(vector<int>& nums,int u){
        if(u==n){
            res.push_back(path);
            return;
        }

        int k=1;
        while(u+k<n&&nums[u]==nums[u+k]) k++;

        for(int i=0;i<=k;i++){
            dfs(nums,u+k);
            path.push_back(nums[u]);
        }

        for(int i=0;i<=k;i++) path.pop_back();//注意恢复现场
    }
};

//递归写法二
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return res;
    }

    /*
    按照集合前缀进行分类 应防止前缀重复出现
    */
    void dfs(vector<int>& nums,int u){
        res.emplace_back(path);
        for(int i=u;i<nums.size();i++){
            path.emplace_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();

            while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        }
    }
};

