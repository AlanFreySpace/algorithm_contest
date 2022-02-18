#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int w[10],dp[105];
//与1035题完全一样
int main(){
    int s,n;
    while(scanf("%d%d",&s,&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++)
            for(int j=s;j>=w[i];j--)
                dp[j]=max(dp[j-w[i]],dp[j]);
        if(dp[s]==1) printf("yes!\n");
        else printf("no!\n");
    }
    return 0;
}
