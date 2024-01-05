class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0, j; i < n;) {// 枚举加油起点
            int leftGas = 0;
            for (j = 0; j < n; j++) {
                int k = (i + j) % n;
                leftGas += (gas[k] - cost[k]);
                if (leftGas < 0) break;
            }

            if (j == n) {
                return i;
            }
            i = i + j + 1;// 注意这里不用取模,当i+j+1>=n时,由于小于n的i被作为加油起点已经被考察过了，
            // 因此无需重复考察,此时将从最外层的for循环跳出
        }

        return -1;
    }
};