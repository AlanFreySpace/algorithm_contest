class Solution {
public:
    // ̰�ķ������Լ�����Ʊ�۸񲻶����߾Ͳ��� ��Ʊ�۸�һ���;���������
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                res += (prices[i] - prices[i - 1]);
            }
        }
        return res;
    }
};