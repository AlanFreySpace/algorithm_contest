class Solution {
public:
    bool search(vector<int>& nums, int target) {//二分查找问题
        int R=nums.size()-1;
        while(R>0&&nums[R]==nums[0]) R--;
        if(!R) return nums[0]==target;

        int l=0,r=R;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(nums[mid]>=nums[0]) l=mid;
            else r=mid-1;
        }

        if(target>=nums[0]) l=0;
        else l++,r=R;

        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        return nums[r]==target;
    }
};
