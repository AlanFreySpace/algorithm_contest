#include <stdio.h>
#include <string.h>
using namespace std;

long long dp[1000005];//注意数组开在main中会堆栈溢出

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        scanf("%lld",&dp[0]);
        long long ans=dp[0];
        for(int i=1;i<n;i++){
            scanf("%lld",&dp[i]);
            if(dp[i-1]>0) dp[i]+=dp[i-1];
            if(ans<dp[i]) ans=dp[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
