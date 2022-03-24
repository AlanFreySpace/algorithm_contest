class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;//注意这样会快些
        for (int i = 0, last = 0; i < nums.size(); i ++ ) {
            last = nums[i] + max(last, 0);
            res = max(res, last);
        }
        return res;
    }
};
