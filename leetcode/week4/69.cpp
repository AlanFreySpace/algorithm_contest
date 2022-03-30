class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x;
        while(l<r){
            int mid=(l+r+1ll)>>1;//long long类型的1 防止越界
            if(mid<=x/mid) l=mid;
            else r=mid-1;
        }
        return r;
    }
};
