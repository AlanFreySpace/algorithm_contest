package week2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p15_2 {
	//优化,时间复杂度为O(n^2)
	public List<List<Integer>> threeSum(int[] nums) {
        int n=nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans=new ArrayList<>();
        
        //确定第一个数
        for(int i=0;i<n;i++){
            if(i!=0&&nums[i]==nums[i-1]) continue;

            //双指针
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                    continue;
                }
                if(sum<0){
                    j++;
                    continue;
                }
                //sum == 0时
                ans.add(Arrays.asList(nums[i],nums[j],nums[k]));
                //去除重复处理
                do{j++;}while(j<k&&nums[j]==nums[j-1]);
                do{k--;}while(j<k&&nums[k]==nums[k+1]);
            }
        }
        return ans;
    }
}
