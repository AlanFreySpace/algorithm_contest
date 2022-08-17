package week1;

import java.util.HashMap;

public class p1 {
	public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> m=new HashMap<>();;
        int[] ans=new int[2];
        for(int i=0;i<nums.length;i++){
            int r=target-nums[i];
            if(m.containsKey(r)){
                ans[0]=m.get(r);
                ans[1]=i;
                return ans;
            }
            m.put(nums[i],i);
        }
        return null;
    }
}
