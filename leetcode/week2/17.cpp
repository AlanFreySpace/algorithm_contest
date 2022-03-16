class Solution {
public:
    vector<string> ans;
    string strs[10]={
        "","","abc","def",
        "ghi","jkl","mno",
        "pqrs","tuv","wxyz"
    };

    vector<string> letterCombinations(string digits) {//使用dfs算法
        if(digits.size()==0) return ans;
        dfs(digits,0,"");
        return ans;
    }
    //对digits第i位数字对应的字母进行深度优先遍历
    void dfs(string& digits,int i,string s){
        if(i==digits.size()) ans.push_back(s);
        else{
            for(auto c:strs[digits[i]-'0'])
                dfs(digits,i+1,s+c);
        }
    }
};
