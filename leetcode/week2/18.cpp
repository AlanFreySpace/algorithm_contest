class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {//双指针算法 和15题思路相同
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            if(i&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                for(int k=j+1,u=nums.size()-1;k<u;k++){
                    if(k>j+1&&nums[k]==nums[k-1]) continue;
                    while(k<u-1&&(long long)nums[i]+nums[j]+nums[k]+nums[u-1]>=target) u--;
                    if((long long)nums[i]+nums[j]+nums[k]+nums[u]==target)
                        res.push_back({nums[i],nums[j],nums[k],nums[u]});
                }
            }
        }
        return res;
    }
};
