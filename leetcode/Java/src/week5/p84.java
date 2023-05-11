package week5;

import java.util.Stack;

public class p84 {
	public int largestRectangleArea(int[] heights) {
        int n=heights.length;
        int[] left=new int[n],right=new int[n];
        
        //利用单调栈找到每个矩形：左边第一个小于其高度的矩形和右边第一个小于其高度的矩形
        Stack<Integer> sk=new Stack<>();
        for(int i=0;i<n;i++){
            while(!sk.empty()&&heights[sk.peek()]>=heights[i]) sk.pop();
            if(!sk.empty()) left[i]=sk.peek();
            else left[i]=-1;
            sk.push(i);
        }

        sk.clear();

        for(int i=n-1;i>=0;i--){
            while(!sk.empty()&&heights[sk.peek()]>=heights[i]) sk.pop();
            if(!sk.empty()) right[i]=sk.peek();
            else right[i]=n;
            sk.push(i);
        }

        //注意怎么寻找最大的矩形，分类标准：考查各以heights[i]为矩形高度的最大矩形
        //在以上矩形中找到最大的即可
        int ans=0;
        for(int i=0;i<n;i++){
            int tmp=(right[i]-left[i]-1)*heights[i];
            if(tmp>ans) ans=tmp;
        }

        return ans;
    }
}
