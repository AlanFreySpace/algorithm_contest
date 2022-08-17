class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;//最终表示新数组长度
        //前两个元素直接保留 后面的元素只需与数组中前面两个元素分别比较
        //只要与其中一个元素不同 数组就可以扩大
        for(auto x:nums)
            if(k<2||(nums[k-1]!=x||nums[k-2]!=x))
                nums[k++]=x;
        return k;
    }
};
