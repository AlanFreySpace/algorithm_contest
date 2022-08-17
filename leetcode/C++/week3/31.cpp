class Solution {
public:
    void nextPermutation(vector<int>& nums) {//O(n)时间复杂度
        int k=nums.size()-1;
        while(k>0&&nums[k-1]>=nums[k]) k--;

        if(k<=0) reverse(nums.begin(),nums.end());
        else{
            int t=k;
            while(t<nums.size()&&nums[t]>nums[k-1]) t++;
            swap(nums[t-1],nums[k-1]);
            reverse(nums.begin()+k,nums.end());//注意这步就可实现升序排列 很巧妙
        }
    }
};
