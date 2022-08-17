class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int> stk;
        vector<int> left(n),right(n);

        for(int i=0;i<n;i++){//单调栈
            while(stk.size()&&h[stk.top()]>=h[i]) stk.pop();
            if(stk.empty()) left[i]=-1;
            else left[i]=stk.top();
            stk.push(i);
        }

        stk=stack<int>();
        for(int i=n-1;i>=0;i--){//单调栈
            while(stk.size()&&h[stk.top()]>=h[i]) stk.pop();
            if(stk.empty()) right[i]=n;
            else right[i]=stk.top();
            stk.push(i);
        }

        int res=0;
        //注意以h[i]以最高柱子时应该找左右两边比它大的柱子的最后位置
        for(int i=0;i<n;i++)
            res=max(res,h[i]*(right[i]-left[i]-1));
        return res;
    }
};
