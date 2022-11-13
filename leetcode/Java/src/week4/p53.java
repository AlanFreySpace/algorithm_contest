package week4;

public class p53 {
	public int maxSubArray(int[] nums) {
        int ans=nums[0],tmp=nums[0];
        for(int i=1;i<nums.length;i++){
            if(tmp<=0) tmp=nums[i];
            else tmp+=nums[i];
            ans=Math.max(tmp,ans); 
        }
        return ans;
    }
}
