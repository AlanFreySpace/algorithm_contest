class Solution {
public:
    //利用上一题的代码
    int maxRectangle(vector<int> h){
        int n=h.size();
        stack<int> stk;
        vector<int> left(n),right(n);

        for(int i=0;i<n;i++){
            while(stk.size()&&h[stk.top()]>=h[i]) stk.pop();
            if(stk.empty()) left[i]=-1;
            else left[i]=stk.top();
            stk.push(i);
        }

        stk=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(stk.size()&&h[stk.top()]>=h[i]) stk.pop();
            if(stk.empty()) right[i]=n;
            else right[i]=stk.top();
            stk.push(i);
        }

        int res=0;
        for(int i=0;i<n;i++)
            res=max(res,h[i]*(right[i]-left[i]-1));
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> h(n,vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j]=='1'){
                    if(i) h[i][j]=h[i-1][j]+1;
                    else h[i][j]=1;
                }

        int res=0;
        for(int i=0;i<n;i++)
            res=max(res,maxRectangle(h[i]));
        return res;
    }
};
