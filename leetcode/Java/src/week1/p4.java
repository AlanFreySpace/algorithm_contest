package week1;

public class p4 {
	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int tot=nums1.length+nums2.length;
        if(tot%2==0){
            int m1=find(nums1,0,nums2,0,tot/2);
            int m2=find(nums1,0,nums2,0,tot/2+1);
            return (m1+m2)/2.0;
        }
        return find(nums1,0,nums2,0,tot/2+1);
    }

    public int find(int[] nums1,int i,int[] nums2,int j,int k){
        if(nums1.length-i>nums2.length-j) return find(nums2,j,nums1,i,k);

        if(k==1){
            if(i==nums1.length) return nums2[j];
            else{
                if(nums1[i]<nums2[j]) return nums1[i];
                return nums2[j];
            }
        }
        if(i==nums1.length) return nums2[j+k-1];

        int si=i+k/2,sj=j+k-k/2;
        if(si>nums1.length) si=nums1.length;
        if(nums1[si-1]<nums2[sj-1])
            return find(nums1,si,nums2,j,k-(si-i));
        else
            return find(nums1,i,nums2,sj,k-(sj-j));
    }
}
