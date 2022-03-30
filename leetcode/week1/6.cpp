class Solution {
public:
    string convert(string s, int n) {//找规律题
        if(n==1) return s;//注意n为1时要特判 否则会死循环
        string res;
        for(int i=0;i<n;i++){
            if(i==0||i==n-1){//第一行和最后一行是一个等差数列
                for(int j=i;j<s.size();j+=(2*n-2)) res+=s[j];
            }else{//其它行是两个等差数列的交错
                for(int j=i,k=2*n-i-2;j<s.size()||k<s.size();j+=(2*n-2),k+=(2*n-2)){
                    if(j<s.size()) res+=s[j];
                    if(k<s.size()) res+=s[k];
                }
            }
        }
        return res;
    }
};
