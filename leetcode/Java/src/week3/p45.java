package week3;

public class p45 {
	public int jump(int[] nums) {
        int n=nums.length,last=0;
        int f[]=new int[n];
        
        /*
         * 本题思想很巧妙 应注意学习这种思想
         * 另外 本题之所以可以这样写的原因是因为题目中说明了:
         * "假设你总是可以到达数组的最后一个位置",这样才可以last不断++从而得到解
         */
        for(int i=1;i<n;i++){
            while(last+nums[last]<i) last++;
            f[i]=f[last]+1;
        }

        return f[n-1];
    }
}
