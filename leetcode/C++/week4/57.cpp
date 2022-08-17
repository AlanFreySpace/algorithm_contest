class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> ans;
        int k=0,n=a.size();
        while(k<n&&a[k][1]<b[0]) ans.push_back(a[k++]);
        if(k<n){
            b[0]=min(b[0],a[k][0]);
            while(k<n&&b[1]>=a[k][0]) b[1]=max(b[1],a[k++][1]);
        }
        ans.push_back(b);//注意插入b的时机,此处容易出错
        while(k<n) ans.push_back(a[k++]);
        return ans;
    }
};
