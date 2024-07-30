class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        /*
        * 在cpp中，默认情况下，对于二维向量，sort对各行按首元素从小到大排序，
        * 即对于{{1,2},{0,3},{3,1}}将排序为{{0,3},{1,2},{3,1}}
        * 关于自定义sort排序规则的方法，见：
        * https://www.cnblogs.com/mld-code-life/p/12722798.html
        */
        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > r) { //区间不重叠 更新答案
                ans.push_back({ l,r });
                l = intervals[i][0], r = intervals[i][1];
            }
            else { //区间重叠 更新右侧端点
                r = max(r, intervals[i][1]);
            }
        }
        ans.push_back({ l,r }); //最后一个区间

        return ans;
    }
};