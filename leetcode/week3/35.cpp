class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //找到大于等于target的第一个位置 可以用[1,3] target=5或2模拟
        int l=0,r=nums.size();

        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>=target) r=mid; //保留较大的位置
            else l=mid+1; //较小的位置不要留
        }
        return l;
    }
};
