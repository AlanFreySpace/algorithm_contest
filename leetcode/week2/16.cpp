class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {//与15题思路相同
        sort(nums.begin(),nums.end());
        int tmp=INT_MAX,res;
        for(int i=0;i<nums.size();i++){
            if(i&&nums[i]==nums[i-1]) continue;
            for(int j=i+1,k=nums.size()-1;j<k;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                while(j<k-1&&nums[i]+nums[j]+nums[k-1]-target>=0) k--;
                int s=nums[i]+nums[j]+nums[k];
                if(tmp>abs(s-target)) tmp=abs(s-target),res=s;
                if(j<k-1){
                    s=nums[i]+nums[j]+nums[k-1];
                    if(tmp>abs(s-target)){
                        tmp=abs(s-target);
                        res=s;
                    }
                }
            }
        }
        return res;
    }
};
