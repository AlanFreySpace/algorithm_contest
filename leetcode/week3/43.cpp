class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size(),m=num2.size();
        vector<int> A,B,res(n+m);
        //向量低位存储低位数字
        for(int i=n-1;i>=0;i--) A.push_back(num1[i]-'0');
        for(int i=m-1;i>=0;i--) B.push_back(num2[i]-'0');
        //先不进位
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                res[i+j]+=(A[i]*B[j]);
        }
        //进位
        for(int i=0,t=0;i<res.size();i++){
            t+=res[i];
            res[i]=t%10;
            t/=10;
        }
        //去掉前导0
        int k=res.size()-1;
        while(k>0&&!res[k]) k--;
        //转为字符串
        string ans;
        for(int i=k;i>=0;i--) ans+=('0'+res[i]);
        return ans;
    }
};
