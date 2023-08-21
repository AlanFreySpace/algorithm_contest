class Solution {
public:
    /*
    res:ÿ��ѭ��ʱ,������prices[i]Ϊ�����۽�����������Ӧ�������Ϊ��ѭ��֮ǰ��
    ��Ʊ��ͼ۸��������������prices[i] - minPrice > res,�����resΪ������
    ����ά���������res���䡣
    minPrice:��ǰѭ����֮ǰѭ��������,��Ʊ����������
    */
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res = max(prices[i] - minPrice, res);
            minPrice = min(minPrice, prices[i]);
        }
        return res;
    }
};