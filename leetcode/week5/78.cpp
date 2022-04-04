class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> path;
            for(int j=0;j<n;j++)
                if((i>>j)&1) path.push_back(nums[j]);//注意与运算是& 别写成&&了
            ans.push_back(path);
        }
        return ans;
    }
};
