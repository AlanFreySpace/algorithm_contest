class Solution {
public:
    // ʹ���������� ʱ�临�Ӷ�O(n)
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