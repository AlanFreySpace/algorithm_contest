#include <stdio.h>
#include <algorithm>
using namespace std;

int nums[2505],dp[2505];
int n;

//方法一:O(n^2)解法
int lengthOfLIS(){
    int ans=1;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++)
            if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
        if(dp[i]>ans) ans=dp[i];
    }
    return ans;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&nums[i]);
        int ans=lengthOfLIS();
        printf("%d\n",ans);
    }
    return 0;
}
