class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
        两个C++的语法:
        1.vector<int>(5,1)表示定义了5个整型元素的向量,且给出每个元素的初值为1
        2.vector<int>& last = res.back();加引用&可提高程序效率，不加引用会把
        res.back()这个vector<int>整个复制一遍给last，加了引用之后就可以省去这
        一次复制的过程了，效率更高
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