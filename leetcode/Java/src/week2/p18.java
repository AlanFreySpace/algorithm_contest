package week2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p18 {
	public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans=new ArrayList<>();
        int n=nums.length;
        Arrays.sort(nums);

        for(int i=0;i<n-3;i++){
            if(i!=0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;

                int l=j+1,r=n-1;
                while(l<r){
                	//注意这里向上类型转换要强转
                    long sum=(long)nums[i]+nums[j]+nums[l]+nums[r];
                    
                    if(sum<target){
                        l++;
                        continue;
                    }
                    if(sum>target){
                        r--;
                        continue;
                    }

                    ans.add(Arrays.asList(nums[i],nums[j],nums[l],nums[r]));
                    do{l++;}while(l<r&&nums[l]==nums[l-1]);
                    do{r--;}while(l<r&&nums[r]==nums[r+1]);
                }
            }
        }
        return ans;
    }
}
