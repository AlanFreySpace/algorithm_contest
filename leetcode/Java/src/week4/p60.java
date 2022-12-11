package week4;

public class p60 {
	public String getPermutation(int n, int k) {
        String ans="";
        boolean[] flag=new boolean[n+1];
        int[] fact=new int[n];
        fact[0]=1;
        for(int i=1;i<n;i++) fact[i]=fact[i-1]*i;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(!flag[j]){
                    if(fact[n-i]<k) k-=fact[n-i];
                    else{
                        ans+=j;
                        flag[j]=true;
                        break;
                    }
                }
            }
        }

        return ans;
    }
}
