package week2;

import java.util.Arrays;

public class p16 {
	//使用15_2中的方法与框架
	public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n=nums.length,ans=Integer.MAX_VALUE;
        
        for(int i=0;i<n;i++){
            if(i!=0&&nums[i]==nums[i-1]) continue;

            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(Math.abs(sum-target)<Math.abs(ans-target)) ans=sum;

                if(sum>target){
                    r--;
                    continue;
                }

                if(sum<target){
                    l++;
                    continue;
                }

                return target;
            }
        }

        return ans;
    }
}
