package week4;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class p56 {
	/*
	 * 注意在 JDK7 版本以上，Comparator要满足自反性，传递性，对称性，
	 * 不然 Arrays.sort，Collections.sort会报IllegalArgumentException异常
	 * 详见:https://blog.csdn.net/qq_37909508/article/details/120915407
	 */
	public int[][] merge(int[][] intervals) {
        List<int[]> list=new ArrayList<>();

        Comparator<int[]> comparator=new Comparator<int[]>(){
            @Override
            public int compare(int[] o1,int[] o2){
                if(o1[0]<o2[0]) return -1;
                else if(o1[0]>o2[0]) return 1;
                else return 0;//注意两数相等时必须返回0
            }
        };
        Arrays.sort(intervals,comparator);
        int l=intervals[0][0],r=intervals[0][1];
        
        for(int i=1;i<intervals.length;i++){
            if(intervals[i][0]>r){
                list.add(new int[]{l,r});
                l=intervals[i][0];
                r=intervals[i][1];
            }else r=Math.max(intervals[i][1],r);
        }
        list.add(new int[]{l,r});

        int[][] ans=new int[list.size()][2];
        for(int i=0;i<list.size();i++)
            ans[i]=list.get(i);
        return ans;
    }
}
