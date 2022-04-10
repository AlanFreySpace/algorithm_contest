class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.emplace_back(0),res.emplace_back(1);
        while(--n){
            int n=res.size();
            for(int i=0;i<n;i++) res[i]*=2;
            for(int i=0;i<n;i++)
                res.emplace_back(res[n-i-1]+1);
        }
        return res;
    }
};
