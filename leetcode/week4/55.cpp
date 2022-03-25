class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int last=0;
        /*
        ������last(last<i)����i,����last�޷�����i,��last��1,
        ��last�ӵ�i,˵����i֮ǰ�ĵ��޷�����i
        */
        for(int i=1;i<n;i++){
            while(last+nums[last]<i&&last<i)
                last++;
            if(last==i) return false;
        }

        return true;
    }
};
