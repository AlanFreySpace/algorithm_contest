class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;

        while(l<r){//�ҵ����������еķֽ��
            int mid=(l+r+1)>>1;//+1��Ϊ�˷�ֹ������ѭ��
            if(nums[mid]>=nums[0]) l=mid;
            else r=mid-1;
        }
        //�õ�target���ĸ�����������
        if(target>=nums[0]) l=0;
        else l=r+1,r=nums.size()-1;

        while(l<r){//���ֲ���target
            int mid=(l+r)>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        //ע������[1] target=0 ��˱���ʹ��r
        if(nums[r]==target) return r;
        else return -1;
    }
};
