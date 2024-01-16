class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < 32; i++) { // 考察各数字二进制的第i+1位
            int cur = 0;
            for (int num : nums) {
                cur += (num >> i & 1); // 对数组中各数字的第i+1位进行累积
            }
            res += (cur % 3 << i);
        }

        return res;
    }
};