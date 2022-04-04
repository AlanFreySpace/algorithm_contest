/*
一个直观的解决方案是使用计数排序的两趟扫描算法,即首先迭代计算出0,1和2元素的个数,
然后按照0,1,2的排序重写当前数组
而我们此处使用一个仅使用常数空间的一趟扫描算法:三指针算法
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int j=0,i=0,k=nums.size()-1;i<=k;){
            if(nums[i]==0) swap(nums[i++],nums[j++]);
            else if(nums[i]==1) i++;
            else swap(nums[k--],nums[i]);
        }
    }
};
