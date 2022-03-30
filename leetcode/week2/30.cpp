class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {//复杂度O(n*w)
        int n=s.size(),m=words.size(),w=words[0].size();
        unordered_map<string,int> rec;
        for(auto& word:words) rec[word]++;//每个单词应出现的次数

        vector<int> res;
        for(int i=0;i<w;i++){
            int cnt=0;//m个窗口中满足要求的单词的个数
            unordered_map<string,int> wd;
            for(int j=i;j+w<=n;j+=w){
                if(j>=i+m*w){//窗口过多 删除一个窗口
                  auto s2=s.substr(j-m*w,w);
                  wd[s2]--;
                  if(wd[s2]<rec[s2]) cnt--;
                }
                auto s1=s.substr(j,w);//增加一个窗口
                wd[s1]++;
                if(wd[s1]<=rec[s1]) cnt++;
                if(cnt==m) res.emplace_back(j-(m-1)*w);
            }
        }
        return res;
    }
};
