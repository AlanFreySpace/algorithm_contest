class Solution {
public:
    /*
    解法一:三次扫描
    1.观察整个图形，考虑对水的面积按列进行拆解
    2.注意到，每个矩形条上方所能接受的水的高度，是由它左边最高的矩形，
    和右边最高的矩形决定的。具体地，假设第i个矩形条的高度为height[i]，
    且矩形条左边最高的矩形条的高度为left_max[i]，右边最高的矩形条高度为
    right_max[i]，则该矩形条上方能接受水的高度为
    min(left_max[i], right_max[i]) - height[i]。
    3.需要分别从左向右扫描求left_max，从右向左求right_max，最后统计答案即可。
    */
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        vector<int> left_max(n),right_max(n);

        left_max[0]=height[0];
        for(int i=1;i<n;i++)
            left_max[i]=max(left_max[i-1],height[i]);

        right_max[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            right_max[i]=max(right_max[i+1],height[i]);

        for(int i=0;i<n;i++)
            ans+=(min(left_max[i],right_max[i])-height[i]);

        return ans;
    }
};

class Solution {
public:
    /*
    解法二:单调栈
    1.换一种思路，考虑每个位置左边和右边第一个比自身不低的矩形条，
    以及三个矩形条构成的U型，相当于对水的面积按行进行拆解。
    2.维护严格单调递减的单调栈。在每次检查栈顶要出栈时，i为右边第一个
    比st.top()不低的矩形，st.top()弹出栈顶，并将其记为top。
    3.假设此时栈中仍然存在矩形，现在st.top()（弹栈后的栈顶）、top与i
    三个位置构成一个U型，其中top位置代表U型的底部，此时可以计算出该U型
    所能接受的水的面积为
    (i - st.top() - 1) * (min(height[st.top()], height[i]) - height[top])。
    4.最后当前矩形进栈。
    */
    int trap(vector<int>& height) {
        int n=height.size(),ans=0;
        stack<int> stk;

        for(int i=0;i<n;i++){
            while(!stk.empty()&&height[stk.top()]<=height[i]){
                int top=stk.top();
                stk.pop();
                if(stk.empty()) break;
                ans+=(min(height[i],height[stk.top()])-height[top])*(i-stk.top()-1);
            }
            stk.push(i);
        }
        return ans;
    }
};
