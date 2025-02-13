package 排序;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class p56_2 {
	public int[][] merge(int[][] intervals) {
        ArrayList<int[]> list = new ArrayList<>();
        /*
    	 * 注意在 JDK7 版本以上，Comparator要满足自反性，传递性，对称性，
    	 * 不然 Arrays.sort，Collections.sort会报IllegalArgumentException异常
    	 * 详见:https://blog.csdn.net/qq_37909508/article/details/120915407
    	 * 第二种排序的方法：使用Comparator
    	 * 以下是Comparator的最佳写法(不要作加减法防止溢出)
    	 */
        Comparator<int[]> cmp = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1,int[] o2) {
                if(o1[0]<o2[0]) {
                    return -1;
                } else if(o1[0]>o2[0]) {
                    return 1;
                } else {
                    return 0;
                }
            }
        };
        Arrays.sort(intervals,cmp);

        int l=intervals[0][0],r=intervals[0][1];
        for(int i=1;i<intervals.length;i++) {
            if(intervals[i][0]>r) {
                list.add(new int[]{l,r});
                l=intervals[i][0];
                r=intervals[i][1];
            } else {
                r=Math.max(intervals[i][1],r);
            }
        }
        list.add(new int[]{l,r});

        return list.toArray(new int[list.size()][2]);
    }
}
