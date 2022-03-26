class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x;
        while(l<r){
            int mid=(l+r+1ll)>>1;//long long���͵�1 ��ֹԽ��
            if(mid<=x/mid) l=mid;
            else r=mid-1;
        }
        return r;
    }
};
