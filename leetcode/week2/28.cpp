class Solution {
public:
    int strStr(string s, string p) {//kmp算法
        if(p.empty()) return 0;
        int n=s.size(),m=p.size();
        s=' '+s,p=' '+p;
        vector<int> next(m+1);//注意这里的声明 容易写错

        //由next[i-1]推next[i]
        for(int i=2,j=0;i<=m;i++){
            //此时j表明p[j]和p[i-1]对齐 j是next[i-1]
            while(j&&p[i]!=p[j+1]) j=next[j];
            if(p[i]==p[j+1]) j++;
            next[i]=j;
        }

        for(int i=1,j=0;i<=n;i++){
            while(j&&s[i]!=p[j+1]) j=next[j];
            if(s[i]==p[j+1]) j++;
            if(j==m) return i-m;
        }
        return -1;
    }
};
