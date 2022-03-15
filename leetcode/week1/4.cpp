class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot=nums1.size()+nums2.size();
        if(tot%2==0){
            int left=find(nums1,0,nums2,0,tot/2);
            int right=find(nums1,0,nums2,0,tot/2+1);
            return (left+right)/2.0;//ע��Ӧ����2.0��ȷ����double
        }
        else return find(nums1,0,nums2,0,tot/2+1);
    }
    /*
    ����nums1[i,nums1.size()-1]��nums2[j,nums2.size()-1]�е�k(k��1��ʼ)���Ԫ��
    ����nums1��������Ԫ��������һЩ,��˸�������Ԫ�ؿ���Խ��,����б߽紦��
    */
    int find(vector<int>& nums1,int i,vector<int>& nums2,int j,int k){
        if(nums1.size()-i>nums2.size()-j) return find(nums2,j,nums1,i,k);
        if(k==1){
            if(nums1.size()==i) return nums2[j];
            else return min(nums1[i],nums2[j]);
        }
        if(nums1.size()==i) return nums2[j+k-1];
        //ע��Ҫ��(int)תΪ���� ע��si�Ķ�����Ϊ�˷�ֹ��� ��Ϊnums1���麬��Ԫ��������Щ
        int si=min(i+k/2,(int)nums1.size()),sj=j+k-k/2;
        if(nums1[si-1]<nums2[sj-1])
            return find(nums1,si,nums2,j,k-(si-i));
        else
            return find(nums1,i,nums2,sj,k-(sj-j));
    }
};
