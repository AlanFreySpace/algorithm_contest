package 哈希表;

import java.util.HashMap;

public class p1 {
	public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> hash = new HashMap<>();

        for(int i=0;i<nums.length;i++) {
            Integer tmp = target-nums[i];
            if(hash.containsKey(tmp)) {
                int[] ans = {hash.get(tmp),i};
                return ans;
            }
            hash.put(nums[i],i);
        }

        return null;
    }
}
