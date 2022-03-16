class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {//双指针解决 时间复杂度O(n^2)
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        //注意要分好类 一直要满足i<j<k
        for(int i=0;i<nums.size();i++){
            if(i&&nums[i]==nums[i-1]) continue;//防止i元素重复
            for(int j=i+1,k=nums.size()-1;j<k;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;//防止j元素重复
                //查找 直到nums[i]+nums[j]+nums[k-1]<0 此时再判定k处即可 这里很巧妙
                while(j<k-1&&nums[i]+nums[j]+nums[k-1]>=0) k--;
                if(nums[i]+nums[j]+nums[k]==0)
                    res.push_back({nums[i],nums[j],nums[k]});
            }
        }
        return res;
    }
};
