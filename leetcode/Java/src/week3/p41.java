package week3;

public class p41 {
	public int firstMissingPositive(int[] nums) {
        int n=nums.length;
        /*
         * 一定要注意 不能写成nums[i]!=i+1 否则用例[1,1]会进入死循环
         * 一定要理清逻辑
         * 关键：
         * 看数字nums[i]对应位置nums[i]-1放的数字对不对
         */
        for(int i=0;i<n;i++)
            while(nums[i]>0&&nums[i]<=n&&nums[i]!=nums[nums[i]-1]){
                int tmp=nums[i];
                nums[i]=nums[nums[i]-1];
                nums[tmp-1]=tmp;
            }
        
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1) return i+1;

        return n+1;
    }
}
