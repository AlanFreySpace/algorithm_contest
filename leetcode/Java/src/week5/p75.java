package week5;

public class p75 {
	public void sortColors(int[] nums) {
        int redNum=0,whiteNum=0,blueNum=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0) redNum++;
            else if(nums[i]==1) whiteNum++;
            else blueNum++;
        }
        for(int i=0;i<redNum;i++) nums[i]=0;
        for(int i=redNum;i<redNum+whiteNum;i++) nums[i]=1;
        for(int i=redNum+whiteNum;i<nums.length;i++) nums[i]=2; 
    }
}
