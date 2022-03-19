class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {//���Ӷ�O(n*w)
        int n=s.size(),m=words.size(),w=words[0].size();
        unordered_map<string,int> rec;
        for(auto& word:words) rec[word]++;//ÿ������Ӧ���ֵĴ���

        vector<int> res;
        for(int i=0;i<w;i++){
            int cnt=0;//m������������Ҫ��ĵ��ʵĸ���
            unordered_map<string,int> wd;
            for(int j=i;j+w<=n;j+=w){
                if(j>=i+m*w){//���ڹ��� ɾ��һ������
                  auto s2=s.substr(j-m*w,w);
                  wd[s2]--;
                  if(wd[s2]<rec[s2]) cnt--;
                }
                auto s1=s.substr(j,w);//����һ������
                wd[s1]++;
                if(wd[s1]<=rec[s1]) cnt++;
                if(cnt==m) res.emplace_back(j-(m-1)*w);
            }
        }
        return res;
    }
};
