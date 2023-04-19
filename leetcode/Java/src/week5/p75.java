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
	
	// 荷兰国旗算法
	public void sortColors1(int[] nums) {
        /**
         * 性质1:[0,j-1]区间为0,[j,i-1]区间为1,[k+1,n-1]区间为2
         * i,j,k分别指示下一个要放0,1,2的位置
         * (1)用数学归纳法可以证明下面的算法始终维持上面的性质:
         *    (i)若nums[i]==0,则交换nums[i]和nums[j],由于交换之前nums[j]=1,则
         * 交换之后[0,j]区间为0,[j+1,i]区间为1,[k+1,n-1]区间为2,则应将i,j分别加1,
         * i,j分别加1后仍满足[0,j-1]区间为0,[j,i-1]区间为1,[k+1,n-1]区间为2
         *    (ii)若nums[i]==1,由于[j,i-1]区间为1,则此时[j,i]区间可确定为1,因此只需将i
         * 加1即可满足性质1
         *    (iii)若nums[i]==2,则交换nums[i]和nums[k]
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
