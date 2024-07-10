class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int sum = 0, res = 0;
        hash[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int tmp = sum - k;
            res += hash[tmp];
            hash[sum]++;
        }

        return res;
    }
};