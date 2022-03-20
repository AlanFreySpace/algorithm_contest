class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //�ҵ����ڵ���target�ĵ�һ��λ�� ������[1,3] target=5��2ģ��
        int l=0,r=nums.size();

        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>=target) r=mid; //�����ϴ��λ��
            else l=mid+1; //��С��λ�ò�Ҫ��
        }
        return l;
    }
};
