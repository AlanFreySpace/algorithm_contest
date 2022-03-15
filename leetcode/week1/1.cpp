class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {//O(n)算法
        unordered_map<int,int> m; //<数字,下标>哈希表
        for(int i=0;i<nums.size();i++){
            int r=target-nums[i];
            if(m.count(r)) return {m[r],i};
            m[nums[i]]=i;
        }
        return {};
    }
};
