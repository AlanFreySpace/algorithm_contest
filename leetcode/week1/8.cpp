class Solution {
public:
    int myAtoi(string s) {
        int k=0;
        //ȥ��ǰ���ո�
        for(int i=0;i<s.size()&&s[i]==' ';i++) k++;
        if(k==s.size()) return 0;
        //���������� ע��ֻ�ܶ�ȡһ�������� ������else if
        int minus=1;
        if(s[k]=='-') minus=-1,k++;
        else if(s[k]=='+') k++;
        //��ȡ����
        int res=0;
        while(k<s.size()&&s[k]>='0'&&s[k]<='9'){
            int x=s[k]-'0';
            if(minus==1&&res>(INT_MAX-x)/10) return INT_MAX;
            if(minus==-1&&-res<(INT_MIN+x)/10) return INT_MIN;
            //����res��������־���ֵ INT��Сֵ�����ֵ�ľ���ֵ��1 ������Ҫ����
            if(minus==-1&&-res*10-x==INT_MIN) return INT_MIN;
            res=res*10+x;
            k++;
        }
        if(minus==-1) res=-res;
        return res;
    }
};
