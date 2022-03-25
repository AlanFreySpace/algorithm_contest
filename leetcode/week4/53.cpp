//解法一:动态规划 时间O(n) 空间O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;//注意这样会快些
        for (int i = 0, last = 0; i < nums.size(); i ++ ) {
            last = nums[i] + max(last, 0);
            res = max(res, last);
        }
        return res;
    }
};

/*
解法二:分治
1.对于一个区间 [l,r],维护四个值,分别是,总和sum,非空最大子段和s,
前缀非空最大子段和ls,后缀非空最大子段和rs
2.分别递归左右子区间
合并时,sum是左右子区间的sum之和
对于s,则有三种情况取最大值:左区间的s,右区间的s,左区间的rs加上右区间的ls
对于ls，则有两种情况取最大值:左区间的ls,左区间的sum加上右区间的ls
对于rs同理
3.合并后返回递归的结果。
时间复杂度由递归主定理T(n)=2T(n/2)+O(1)T(n)=2T(n/2)+O(1)，解出总时间复杂度为O(n)
空间复杂度需要额外O(log⁡n)的空间用于递归的系统栈
*/
struct Node{
    int sum,s,ls,rs;
    Node(int _sum,int _s,int _ls,int _rs){
        sum=_sum,s=_s,ls=_ls,rs=_rs;
    }
};

class Solution {
public:
    Node solve(vector<int>& nums,int l,int r){
        if(l==r)
            return Node(nums[l],nums[l],nums[l],nums[l]);

        int m=(l+r)>>1;

        Node left=solve(nums,l,m);
        Node right=solve(nums,m+1,r);

        return Node(left.sum+right.sum,
                max(max(left.s,right.s),left.rs+right.ls),
                max(left.ls,left.sum+right.ls),
                max(right.rs,right.sum+left.rs));
    }

    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1).s;
    }
};

