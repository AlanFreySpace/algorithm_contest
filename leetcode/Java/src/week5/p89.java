package week5;

import java.util.ArrayList;
import java.util.List;

public class p89 {
	public List<Integer> grayCode(int n) {
	       List<Integer> ans=new ArrayList<>(); 
	       ans.add(0);
	       ans.add(1);

	       for(int i=2;i<=n;i++){
	           int len=ans.size();
	           for(int j=0;j<len;j++) ans.set(j,ans.get(j)<<1);
	           for(int j=0;j<len;j++) ans.add(ans.get(len-j-1)+1);
	       }

	       return ans;
	    }
}
