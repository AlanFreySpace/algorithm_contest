package week5;

public class p74 {
	public boolean searchMatrix(int[][] matrix, int target) {
        int m=matrix.length,n=matrix[0].length;
        int l=0,r=m-1,mid=m/2;
        while(l<r){//找到第一列中小于等于target的最大元素
            if(matrix[mid][0]>target) r=mid-1;
            else l=mid;
            mid=(l+r+1)/2;
        }
        if(matrix[mid][0]>target) return false;
        if(matrix[mid][0]==target) return true;
        int row=mid;
        l=0;
        r=n-1;
        mid=n/2;
        while(l<r){
            if(matrix[row][mid]>target) r=mid-1;
            else l=mid;
            mid=(l+r+1)/2;
        }
        if(matrix[row][mid]==target) return true;
        return false;
    }
}
