class Solution {
public:
    int romanToInt(string s) {//模拟+找规律
        unordered_map<char,int> hash;
        hash['I']=1,hash['V']=5;
        hash['X']=10,hash['L']=50;
        hash['C']=100,hash['D']=500;
        hash['M']=1000;
        int res=0;
        for(int i=0;i<s.size()-1;i++){
            if(hash[s[i]]<hash[s[i+1]]) res-=hash[s[i]];//注意该规律
            else res+=hash[s[i]];
        }
        res+=hash[s[s.size()-1]];
        return res;
    }
};
