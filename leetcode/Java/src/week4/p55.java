package week4;

public class p55 {
	public boolean canJump(int[] nums) {
        int j=0;//由j跳到i

        for(int i=1;i<nums.length;i++){
            while(j+nums[j]<i) j++;
            if(j==i) return false;
        }

        return true;
    }
}
