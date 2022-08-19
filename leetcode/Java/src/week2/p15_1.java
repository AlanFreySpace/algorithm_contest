package week2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//方法一 时间复杂度较高,为O(n^3)
public class p15_1 {
	public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<ArrayList<Integer>> ans=new ArrayList<>();

        for(int i=0;i<nums.length;i++){
            if(i!=0&&nums[i]==nums[i-1]) continue;
            //注意这里条件是j<nums.length-1,不要写成j<nums.length,否则会出错
            for(int j=i+1;j<nums.length-1;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int k=nums.length-1;
                while(j<k-1&&nums[i]+nums[j]+nums[k-1]>=0) k--;
                if(nums[i]+nums[j]+nums[k]==0)
                    ans.add(new ArrayList<>(Arrays.asList(nums[i],nums[j],nums[k])));
            }
        }
        return (List)ans;
    }
}
