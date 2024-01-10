class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 1;
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
                if (dec == inc) {
                    dec++;
                }
                res += dec;
                pre = 1;
            }
        }

        return res;
    }
};