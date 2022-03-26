class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        /*
        对于二维向量,sort不对向量每一行内元素排序,而对
        各行按首元素排序
        */
        sort(a.begin(),a.end());
        int l=a[0][0],r=a[0][1];

        for(int i=1;i<a.size();i++){
            if(r<a[i][0]){//区间不重叠 更新答案
                ans.push_back({l,r});
                l=a[i][0],r=a[i][1];
            }else r=max(r,a[i][1]);//区间重叠 更新右侧端点
        }
        ans.push_back({l,r});//最后一个区间
        return ans;
    }
};
