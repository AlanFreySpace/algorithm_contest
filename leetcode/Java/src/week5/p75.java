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
	
	public void sortColors1(int[] nums) {
        /**
         * 初始状态:(可确认)[0,j-1]区间为0,[j,i-1]区间为1,[k+1,n-1]区间为2
         */
		for(int i=0,j=0,k=nums.length-1;i<=k;){
            int tmp=0;
            if(nums[i]==0) {
                tmp=nums[i];
                nums[i++]=nums[j];
                nums[j++]=tmp;
            }
            else if(nums[i]==1) i++;
            else {
                tmp=nums[i];
                nums[i]=nums[k];
                nums[k--]=tmp;
            }
        }
    }
}
