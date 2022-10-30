package week3;

public class p31 {
	public void nextPermutation(int[] nums) {
        int k=nums.length,i=k-1;
        while(i>0&&nums[i]<=nums[i-1]) i--;

        if(i==0) reverse(nums,0,k-1);
        else{
            int t=k-1;
            //此处应尤其注意,将刚好大于nums[i-1]的数字换过来
            while(t>i-1&&nums[i-1]>=nums[t]) t--;
            swap(nums,t,i-1);
            reverse(nums,i,k-1);
        }
    }

    public void swap(int[] a,int l,int r){
        int tmp=a[l];
        a[l]=a[r];
        a[r]=tmp;
    }

    public void reverse(int[] a,int l,int r){
        if(l==r) return;
        while(l<r){
            swap(a,l,r);
            l++;
            r--;
        }
    }
}
