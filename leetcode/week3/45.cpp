class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> f(n);
        int last=0;

        /*
        i����Ҫ������λ��,�����last�Ƿ�������i
        ������,��last+nums[last]<i�����last��λ��
        �ٿ���,���򵽴�i�������������Ϊf[last]+1
        ÿ������౻�������� ���ʱ�临�Ӷ�ΪO(n)
        */
        for(int i=1;i<n;i++){
            while(last+nums[last]<i)
                last++;
            f[i]=f[last]+1;
        }
        return f[n-1];
    }
};
