package week5;

public class p80 {
	public int removeDuplicates(int[] nums) {
        int count=1,i=0,j=1;
        for(i=0,j=1;i<nums.length-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }
            else{
                nums[j]=nums[i+1];
                count=1;
            }
            if(count<=2) j++;
        }
        return j;
    }
}
