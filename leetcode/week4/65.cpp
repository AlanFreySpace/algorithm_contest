class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        bool numerical=scanInteger(s,i);
        //ע��˴�ע��||�Ķ�·���� Ӧȷ��i��1 scanUnsignedInteger(s,++i)Ӧ�÷���ǰ��
        if(i<s.size()&&s[i]=='.')//ɨ�����
            numerical=scanUnsignedInteger(s,++i)||numerical;
        if(i<s.size()&&(s[i]=='e'||s[i]=='E'))//ɨ��ָ��
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
