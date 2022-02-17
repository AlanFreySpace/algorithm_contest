#include <stdio.h>
#include <algorithm>
using namespace std;

int n,a[1005],dp[1005];
//dp[i]代表以a[i]结尾的上升子序列的最大和
void sumOfBIS(){
    int ans=a[0];
    for(int i=0;i<n;i++){
        dp[i]=a[i];
        for(int j=0;j<i;j++)
            if(a[j]<a[i]) dp[i]=max(dp[i],a[i]+dp[j]);
        if(dp[i]>ans) ans=dp[i];
    }
    printf("%d\n",ans);
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sumOfBIS();
    }
    return 0;
}
