class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
        ����C++���﷨:
        1.vector<int>(5,1)��ʾ������5������Ԫ�ص�����,�Ҹ���ÿ��Ԫ�صĳ�ֵΪ1
        2.vector<int>& last = res.back();������&����߳���Ч�ʣ��������û��
        res.back()���vector<int>��������һ���last����������֮��Ϳ���ʡȥ��
        һ�θ��ƵĹ����ˣ�Ч�ʸ���
        */
        vector<vector<int>> res;
        res.push_back(vector<int>(1, 1));

        for (int i = 1; i < numRows; i++) {
            vector<int>& last = res.back();
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < i; j++) {
                temp.push_back(last[j - 1] + last[j]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }

        return res;
    }
};