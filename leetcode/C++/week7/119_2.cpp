class Solution {
public:
    // 使用组合数解决 时间复杂度O(n)
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);

        for (int i = 0; i < rowIndex; i++) {
            int tmp = (long)res[i] * (rowIndex - i) / (i + 1);
            res.push_back(tmp);
        }

        return res;
    }
};