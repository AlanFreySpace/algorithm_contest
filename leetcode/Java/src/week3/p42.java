package week3;

import java.util.Stack;

public class p42 {
	/*
	 * 方法一,三次扫描:再次注意,三次扫描方法中,left_max[i]代表[0,i]区间中最高的柱子，
	 * 而不是[0,i)区间。
	 */
	public int trap(int[] height) {
        int n=height.length,ans=0;
        int[] left_max=new int[n],right_max=new int[n];
        left_max[0]=height[0];
        right_max[n-1]=height[n-1];

        for(int i=1;i<n;i++)
            left_max[i]=Math.max(left_max[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            right_max[i]=Math.max(right_max[i+1],height[i]);
        for(int i=0;i<n;i++)
            ans+=Math.min(left_max[i],right_max[i])-height[i];

        return ans;
    }
}

 class p42_1{
	 /*
	  * 方法二:单调栈,C++代码中的解法描述是不直观而且繁琐的,而且有一些小的错误,
	  * 现在直观描述单调栈的解法:
	  * 单调栈中存下标,各下标i对应的元素height[i]从栈底到栈顶是严格单调递减的,设
	  * 栈顶存的索引是top,当前遍历到元素的索引是i,若height[top]<=height[i],则由
	  * 当前遍历元素、栈顶元素、栈顶元素的下一个元素组成U型,否则height[top]>height[i],
	  * 则将i压栈,继续组成单调栈
	  */
	 public int trap(int[] height) {
	        Stack<Integer> stk=new Stack<>();
	        int ans=0;

	        for(int i=0;i<height.length;i++){
	            while(!stk.empty()&&height[i]>=height[stk.peek()]){
	                int top=stk.peek();
	                stk.pop();
	                if(stk.empty()) break;
	                ans+=(i-stk.peek()-1)*(Math.min(height[i],height[stk.peek()])-height[top]);
	            }
	            stk.push(i);
	        }

	        return ans;
	    }
 }
