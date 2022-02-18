#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct grass{
    int time,value;
}g[105];

int dp[1005];

int main(){
    int t,m;
    while(scanf("%d%d",&t,&m)!=EOF){
        for(int i=1;i<=m;i++) scanf("%d%d",&g[i].time,&g[i].value);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
            for(int j=t;j>=g[i].time;j--)
                dp[j]=max(dp[j],dp[j-g[i].time]+g[i].value);
        printf("%d\n",dp[t]);
    }
    return 0;
}
