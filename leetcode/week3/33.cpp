class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;

        while(l<r){//找到两上升序列的分界点
            int mid=(l+r+1)>>1;//+1是为了防止陷入死循环
            if(nums[mid]>=nums[0]) l=mid;
            else r=mid-1;
        }
        //得到target在哪个有序序列中
        if(target>=nums[0]) l=0;
        else l=r+1,r=nums.size()-1;

        while(l<r){//二分查找target
            int mid=(l+r)>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        //注意用例[1] target=0 因此必须使用r
        if(nums[r]==target) return r;
        else return -1;
    }
};
