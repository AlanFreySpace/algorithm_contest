/*
方法一:超时递归算法,时间复杂度O(5^n)
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        string ss1=s1,ss2=s2;
        sort(ss1.begin(),ss1.end());
        sort(ss2.begin(),ss2.end());
        if(ss1!=ss2) return false;

        int n=s1.size();
        for(int i=1;i<n;i++){
            //分割后不交换字符串
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&
            isScramble(s1.substr(i),s2.substr(i)))
                return true;
            //分割后交换字符串
            if(isScramble(s1.substr(0,i),s2.substr(n-i))&&
            isScramble(s1.substr(i),s2.substr(0,n-i)))
                return true;
        }
        return false;
    }
};

/*
方法二:区间dp 时间复杂度O(n^4)
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        vector<vector<vector<bool>>> f(n,vector<vector<bool>>(n,vector<bool>(n+1)));

        for(int k=1;k<=n;k++){
            for(int i=0;i<n-k+1;i++){//注意要尤其注意i和j的边界
                for(int j=0;j<n-k+1;j++){
                    if(k==1){
                        if(s1[i]==s2[j]) f[i][j][k]=true;
                    }
                    else{
                        for(int u=1;u<k;u++){
                            if((f[i][j][u]&&f[i+u][j+u][k-u])||
                            (f[i][j+k-u][u]&&f[i+u][j][k-u])){
                                f[i][j][k]=true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return f[0][0][n];
    }
};
