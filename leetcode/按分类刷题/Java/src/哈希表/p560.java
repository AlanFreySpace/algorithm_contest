package 哈希表;

import java.util.HashMap;

public class p560 {
	public int subarraySum(int[] nums, int k) {
        Integer sum = 0, res = 0;
        HashMap<Integer,Integer> hash = new HashMap<>();
        hash.put(0,1);

        for(int i=0;i<nums.length;i++) {
            sum+=nums[i];
            Integer tmp = sum-k;
            if(hash.containsKey(tmp)) {
                res += hash.get(tmp);
            } 
            if(hash.containsKey(sum)) {
                hash.put(sum,hash.get(sum)+1);
            } else {
                hash.put(sum,1);
            }
        }

        return res;
    }
}
