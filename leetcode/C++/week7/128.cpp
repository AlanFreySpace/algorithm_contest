class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // ʹ��nums�е�ȫ��Ԫ�س�ʼ��unordered_set
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;

        for (int num : nums) {
            if (set.find(num - 1) == set.end()) { // ��num��ʼ����
                int end = num;
                while (set.find(end) != set.end()) { //��num��ʼ���ҿ�
                    end++;
                }
                ans = max(ans, end - num);
            }
        }

        return ans;
    }
};