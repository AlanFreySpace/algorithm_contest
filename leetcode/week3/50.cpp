class Solution {
public:
    double myPow(double x, int n) {
        typedef long long ll;
        bool is_minus=n<0;
        double res=1;
        //快速幂算法
        for(ll k=abs(ll(n));k;k>>=1){
            if(k&1) res*=x;
            x*=x;
        }

        if(is_minus) res=1/res;
        return res;
    }
};
