class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0,"");
        return ans;
    }

    void dfs(int n,int l,int r,string s){
        if(l==n&&r==n) ans.push_back(s);
        else{
            if(l<n) dfs(n,l+1,r,s+'(');
            if(r<n&&l>r) dfs(n,l,r+1,s+')');
        }
    }
};
