class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n);
        int last=0;

        /*
        i是想要跳到的位置,考察从last是否能跳到i
        若不能,即last+nums[last]<i则更改last的位置
        再考察,否则到达i所需的最少跳数为f[last]+1
        每个点最多被访问两次 因此时间复杂度为O(n)
        */
        for(int i=1;i<n;i++){
            while(last+nums[last]<i)
                last++;
            f[i]=f[last]+1;
        }
        return f[n-1];
    }
};
