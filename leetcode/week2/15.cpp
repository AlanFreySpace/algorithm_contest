class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {//˫ָ���� ʱ�临�Ӷ�O(n^2)
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        //ע��Ҫ�ֺ��� һֱҪ����i<j<k
        for(int i=0;i<nums.size();i++){
            if(i&&nums[i]==nums[i-1]) continue;//��ֹiԪ���ظ�
            for(int j=i+1,k=nums.size()-1;j<k;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;//��ֹjԪ���ظ�
                //���� ֱ��nums[i]+nums[j]+nums[k-1]<0 ��ʱ���ж�k������ ���������
                while(j<k-1&&nums[i]+nums[j]+nums[k-1]>=0) k--;
                if(nums[i]+nums[j]+nums[k]==0)
                    res.push_back({nums[i],nums[j],nums[k]});
            }
        }
        return res;
    }
};
