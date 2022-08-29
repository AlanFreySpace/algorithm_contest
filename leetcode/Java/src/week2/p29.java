package week2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p29 {
	public int divide(int dividend, int divisor) {
        int min_value=Integer.MIN_VALUE/2;
        int x=dividend,y=divisor;
        boolean sign=(x>0)^(y>0);
        if(x>0) x=-x;
        if(y>0) y=-y;

        List<List<Integer>> ls=new ArrayList<>();
        for(int i=y,j=-1;;i+=i,j+=j){
            ls.add(Arrays.asList(i,j));
            if(i<min_value) break;
        }

        int ans=0;
        for(int i=ls.size()-1;i>=0;i--){
            if(x<=ls.get(i).get(0)){
                ans+=ls.get(i).get(1);
                x-=ls.get(i).get(0);
            }
        }

        if(!sign){
            if(ans==Integer.MIN_VALUE) return Integer.MAX_VALUE;
            ans=-ans;
        }
        return ans;
   }
}
