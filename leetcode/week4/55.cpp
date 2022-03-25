class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=0;
        /*
        尝试由last(last<i)跳到i,若从last无法跳到i,则last加1,
        若last加到i,说明由i之前的点无法跳到i
        */
        for(int i=1;i<n;i++){
            while(last+nums[last]<i&&last<i)
                last++;
            if(last==i) return false;
        }

        return true;
    }
};
