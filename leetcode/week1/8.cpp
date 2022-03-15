class Solution {
public:
    int myAtoi(string s) {
        int k=0;
        //去掉前导空格
        for(int i=0;i<s.size()&&s[i]==' ';i++) k++;
        if(k==s.size()) return 0;
        //读入正负号 注意只能读取一个正负号 所以用else if
        int minus=1;
        if(s[k]=='-') minus=-1,k++;
        else if(s[k]=='+') k++;
        //读取数字
        int res=0;
        while(k<s.size()&&s[k]>='0'&&s[k]<='9'){
            int x=s[k]-'0';
            if(minus==1&&res>(INT_MAX-x)/10) return INT_MAX;
            if(minus==-1&&-res<(INT_MIN+x)/10) return INT_MIN;
            //由于res存的是数字绝对值 INT最小值比最大值的绝对值大1 所以需要特判
            if(minus==-1&&-res*10-x==INT_MIN) return INT_MIN;
            res=res*10+x;
            k++;
        }
        if(minus==-1) res=-res;
        return res;
    }
};
