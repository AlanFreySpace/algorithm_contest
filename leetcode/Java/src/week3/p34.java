package week3;

public class p34 {
	public int[] searchRange(int[] nums, int target) {
        int[] res={-1,-1};
        if(nums.length==0) return res;

        int l=0,r=nums.length-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        if(nums[r]!=target) return res;
        res[0]=r;

        l=r;
        r=nums.length-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(nums[mid]<=target) l=mid;
            else r=mid-1;
        }
        res[1]=l;

        return res;
    }
}
