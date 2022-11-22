package week4;

import java.util.ArrayList;
import java.util.List;

public class p57 {
	public int[][] insert(int[][] a, int[] b) {
        List<int[]> list=new ArrayList<>();
        int k=0,n=a.length;

        while(k<n&&a[k][1]<b[0]) list.add(a[k++]);//b[0]前面的a[k]
        if(k<n){//b与a[k]重叠的部分
            b[0]=Math.min(a[k][0],b[0]);
            while(k<n&&b[1]>=a[k][0]) b[1]=Math.max(b[1],a[k++][1]);
        }
        list.add(b);
        while(k<n) list.add(a[k++]);//b[1]后面的a[k]

        int[][] ans=new int[list.size()][2];
        for(int i=0;i<list.size();i++) ans[i]=list.get(i);
        return ans;
    }
}
