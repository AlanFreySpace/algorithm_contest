package week2;

public class p27 {
	//等于val的跳过去 不等于的赋值前移
	public int removeElement(int[] nums, int val) {
        int k=0;
        for(int i=0;i<nums.length;i++)
            if(nums[i]!=val) nums[k++]=nums[i];
        return k;
    }
}
