package week2;

public class p26 {
	//双指针
	public int removeDuplicates(int[] nums) {
        int k=1;//k左指针 i右指针
        for(int i=1;i<nums.length;i++)
            if(nums[i]!=nums[i-1]) nums[k++]=nums[i];
        return k;
    }
}
