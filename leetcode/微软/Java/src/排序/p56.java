package 排序;

import java.util.ArrayList;
import java.util.Arrays;

public class p56 {
	public int[][] merge(int[][] intervals) {
        ArrayList<int[]> list = new ArrayList<>();

        Arrays.sort(intervals,(x,y) -> x[0]-y[0]);
        int l=intervals[0][0],r=intervals[0][1];

        for(int i=1;i<intervals.length;i++) {
            if(intervals[i][0]>r) {
                list.add(new int[]{l,r});
                l=intervals[i][0];
                r=intervals[i][1];
            } else {
                r=Math.max(r,intervals[i][1]);
            }
        }
        list.add(new int[]{l,r});

        return list.toArray(new int[list.size()][2]);
    }
}
