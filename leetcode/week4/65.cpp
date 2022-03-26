class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        bool numerical=scanInteger(s,i);
        //注意此处注意||的短路现象 应确保i加1 scanUnsignedInteger(s,++i)应该放在前面
        if(i<s.size()&&s[i]=='.')//扫描底数
            numerical=scanUnsignedInteger(s,++i)||numerical;
        if(i<s.size()&&(s[i]=='e'||s[i]=='E'))//扫描指数
            numerical=numerical&&scanInteger(s,++i);
        return numerical&&i==s.size();
    }

    bool scanInteger(string& s,int& pos){
        if(s[pos]=='+'||s[pos]=='-') pos++;
        return scanUnsignedInteger(s,pos);
    }

    bool scanUnsignedInteger(string& s,int& pos){
        int p=pos;
        while(pos<s.size()&&s[pos]>='0'&&s[pos]<='9') pos++;
        return p<pos;
    }
};
