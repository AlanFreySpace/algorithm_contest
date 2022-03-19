class Solution {
public:
    /*
    1.根据 dividend 和 divisor 的符号判断最终答案的符号。
    2.如果 dividend 或 divisor 为正数，则变为负数，因为负数的数域比正数多 1。
    3.采用倍增的方式，首先通过自加预处理一个二元组倍增数组：(divisor, -1),
    (2 * divisor, -2), (4 * divisor, -4)，……， 直到 2^k * divisor 小于了 dividend，但中途注意判断越界。
    4.倒序遍历这个倍增数组，如果 dividend 小于当前项，则让 dividend 减去当前项，累计负答案，以此类推。
    */
    int divide(int dividend, int divisor) {
        const int HALF_INT_MIN=-1073741824;//-2^30
        int x=dividend,y=divisor;
        bool sign=(x>0)^(y>0);
        if(x>0) x=-x;
        if(y>0) y=-y;

        vector<pair<int,int> > vec;
        for(int t1=y,t2=-1;t1>=x;t1+=t1,t2+=t2){
            vec.emplace_back(t1,t2);
            if(t1<HALF_INT_MIN) break;
        }

        int ans=0;
        for(int i=vec.size()-1;i>=0;i--){
            if(x<=vec[i].first){
                x-=vec[i].first;
                ans+=vec[i].second;
            }
        }

        if(!sign){
            if(ans==INT_MIN)
                return INT_MAX;
            ans=-ans;
        }
        return ans;
    }
};
