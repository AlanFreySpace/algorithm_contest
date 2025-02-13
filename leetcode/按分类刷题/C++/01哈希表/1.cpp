class Solution {
public:
    /**
    * count函数用以统计key值在unordered_map中出现的次数。实际上，
    * c++ unordered_map不允许有重复的key。因此，如果key存在，则count返回1，
    * 如果不存在，则count返回0
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            int tmp = target - nums[i];
            if (hash.count(tmp)) {
                return { hash[tmp],i };
            }
            hash[nums[i]] = i;
        }

        return {};
    }
};