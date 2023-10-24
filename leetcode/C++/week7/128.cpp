class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 使用nums中的全部元素初始化unordered_set
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;

        for (int num : nums) {
            if (set.find(num - 1) == set.end()) { // 从num开始向左看
                int end = num;
                while (set.find(end) != set.end()) { //从num开始向右看
                    end++;
                }
                ans = max(ans, end - num);
            }
        }

        return ans;
    }
};