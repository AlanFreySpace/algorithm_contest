package week5;

public class p80 {
	public int removeDuplicates(int[] nums) {
        int len=nums.length,j=2;
        if(len<3) return len;
        for(int i=2;i<len;i++){
        	// 注意考虑的逻辑:考虑nums[0..j-1](已满足题意的序列)如何扩张
            if(nums[j-1]!=nums[i]||nums[j-2]!=nums[i]) nums[j++]=nums[i];
        }
        return j;
    }
}
