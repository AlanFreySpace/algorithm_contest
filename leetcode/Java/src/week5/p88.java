package week5;

public class p88 {
	public void merge(int[] nums1, int m, int[] nums2, int n) {
        int point1=m-1,point2=n-1,point=m+n-1;
        while(point1>=0&&point2>=0){
            if(nums1[point1]>nums2[point2]){
                nums1[point--]=nums1[point1--];
            }
            else{
                nums1[point--]=nums2[point2--];
            }
        }
        //注意这步是不需要的，因为这步相当于将nums1中自己的值赋值给自己
        //while(point1>=0) nums1[point--]=nums1[point1--];
        while(point2>=0) nums1[point--]=nums2[point2--];
    }
}
