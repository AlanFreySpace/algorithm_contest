class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {//O(n)ʱ�临�Ӷ� O(1)�ռ临�Ӷ�
        int n=nums.size();
        //nums������1-n֮�������iӦ��λ��i-1��
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
