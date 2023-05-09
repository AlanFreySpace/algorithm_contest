package week5;

public class p81 {
	public boolean search(int[] nums, int target) {
		/**
		 * 1.利用二分法得到nums数组中最大的元素，为此，需要去掉数组末尾和nums[0]相同的元素，
		 *   否则，若mid落入数组末尾和nums[0]相同的元素，则mid一直会往后移动反而找不到最大元素
		 */
        int R=nums.length-1;
        while(R>0&&nums[R]==nums[0]) R--;
        if(R==0) return nums[0]==target;

        /**
         * 2.二分法找nums中的最大元素,最后l==r,且[0,l]中的元素>=nums[0],
         * [l+1,R]中的元素<nums[0]
         */
        int l=0,r=R;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(nums[mid]>=nums[0]) l=mid;
            else r=mid-1;
        }

        if(target>=nums[0]) l=0;
        else{
            l++;
            r=R;
        }

        /**
         * 3.二分法找target,注意应用nums[r]==target判断,因为l可能等于nums.length而越界
         */
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }

        return nums[r]==target;
    }
}
