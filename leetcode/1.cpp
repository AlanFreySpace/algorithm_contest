class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {//O(n)�㷨
        unordered_map<int,int> m; //<����,�±�>��ϣ��
        for(int i=0;i<nums.size();i++){
            int r=target-nums[i];
            if(m.count(r)) return {m[r],i};
            m[nums[i]]=i;
        }
        return {};
    }
};
