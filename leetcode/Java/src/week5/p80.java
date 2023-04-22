package week5;

public class p80 {
	public int removeDuplicates(int[] nums) {
        int count=0,i=1,j=1;
        for(i=1,j=1;i<nums.length;i++){
            if(nums[i]==nums[i-1]){
                count++; 
            }
            else{
                count=0;
            }
            if(count<2){
                nums[j++]=nums[i];
            }
        }
        return j;
    }
}
