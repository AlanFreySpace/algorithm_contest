class Solution {
public:
    // 滚动数组解决 时间复杂度O(n*n)
    vector<int> getRow(int rowIndex) {
        vector<int> last;
        last.push_back(1);

        for (int i = 0; i < rowIndex; i++) {
            vector<int> now;
            now.push_back(1);
            for (int j = 0; j < i; j++) {
                now.push_back(last[j] + last[j + 1]);
            }
            now.push_back(1);
            last = now;
        }

        return last;
    }
};