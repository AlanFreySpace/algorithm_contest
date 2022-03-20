class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
        int l=0,r=nums.size()-1;

        while(l<r){//查找最左侧的位置(考查数组中所有元素相同 则r不断左移)
            int mid=(l+r)>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        if(nums[r]!=target) return {-1,-1};

        int L=r;
        l=r,r=nums.size()-1;
        while(l<r){//查找最右侧的位置(考查数组中所有元素相同 则l不断右移)
            int mid=(l+r+1)>>1;
            if(nums[mid]<=target) l=mid;
            else r=mid-1;
        }
        return {L,r};
    }
};
