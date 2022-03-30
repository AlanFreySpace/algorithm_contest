class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {//O(n)时间复杂度 O(1)空间复杂度
        int n=nums.size();
        //nums数组中1-n之间的数字i应在位置i-1处
        for(int i=0;i<n;i++){
            while(nums[i]>0&&nums[i]<=n&&nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
