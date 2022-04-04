class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int l=0,r=n*m-1;

        while(l<r){//二分查找
            int mid=(l+r)>>1;
            if(matrix[mid/m][mid%m]>=target) r=mid;
            else l=mid+1;
        }

        return matrix[r/m][r%m]==target;
    }
};
