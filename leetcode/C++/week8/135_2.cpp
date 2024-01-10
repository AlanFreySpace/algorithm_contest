class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 1; // 最终结果
        /*
        * inc:递增序列长度,同时为递减序列是否要做糖果数修正做参照，即到达递减序列时，
        * 该值会记录上一个递增序列的长度
        * dec:递减序列长度
        * pre:实时递增序列长度
        */
        int inc = 1, dec = 0, pre = 1;

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = (ratings[i] == ratings[i - 1] ? 1 : pre + 1);
                res += pre;
                inc = pre;
            }
            else {
                dec++;
                if (dec == inc) {// 修正峰顶(山顶)糖果数
                    dec++;
                }
                res += dec;
                pre = 1;
            }
        }

        return res;
    }
};