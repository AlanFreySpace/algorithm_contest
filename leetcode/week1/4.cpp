class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot=nums1.size()+nums2.size();
        if(tot%2==0){
            int left=find(nums1,0,nums2,0,tot/2);
            int right=find(nums1,0,nums2,0,tot/2+1);
            return (left+right)/2.0;//注意应除以2.0以确保是double
        }
        else return find(nums1,0,nums2,0,tot/2+1);
    }
    /*
    查找nums1[i,nums1.size()-1]和nums2[j,nums2.size()-1]中第k(k从1开始)大的元素
    其中nums1数组所含元素总是少一些,因此该数组中元素可能越界,需进行边界处理
    */
    int find(vector<int>& nums1,int i,vector<int>& nums2,int j,int k){
        if(nums1.size()-i>nums2.size()-j) return find(nums2,j,nums1,i,k);
        if(k==1){
            if(nums1.size()==i) return nums2[j];
            else return min(nums1[i],nums2[j]);
        }
        if(nums1.size()==i) return nums2[j+k-1];
        //注意要加(int)转为常数 注意si的定义是为了防止溢出 因为nums1数组含的元素总是少些
        int si=min(i+k/2,(int)nums1.size()),sj=j+k-k/2;
        if(nums1[si-1]<nums2[sj-1])
            return find(nums1,si,nums2,j,k-(si-i));
        else
            return find(nums1,i,nums2,sj,k-(sj-j));
    }
};
