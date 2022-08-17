class Solution {
public:
    int numTrees(int n) {//利用记忆化搜索解决问题
        vector<int> f(n+1);
        f[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)
                f[i]+=(f[j-1]*f[i-j]);
        }
        return f[n];
    }
};

class Solution {
public:
    int numTrees(int n) {//使用catalan(n)与catalan(n-1)之间的关系解决
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*(4*i-2)/(i+1);
        }
        return ans;
    }
};
