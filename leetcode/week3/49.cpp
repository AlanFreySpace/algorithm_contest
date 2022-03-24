class Solution {
public:
    //emplace_back和move均避免了拷贝操作 提高效率
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> hash;
       for(auto& str:strs){
           string tmp=str;
           sort(tmp.begin(),tmp.end());
           hash[tmp].emplace_back(move(str));
       }

       vector<vector<string>> ans;
       for(auto& item:hash)
            ans.emplace_back(move(item.second));
       return ans;
    }
};
