#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[1005][105],buy[1005];
struct snack{
    int price,favor;
}s[1005];

int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d%d",&s[i].price,&s[i].favor);
        memset(dp,0,sizeof(dp));
        memset(buy,0,sizeof(buy));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(s[i].price>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-s[i].price]+s[i].favor);
            }
        if(dp[n][m]==0) printf("0\n");
        else{
            int col=m;
            for(int i=n;i>0&&dp[i][col]>0;i--)//是否购买了第i件物品?
                if(dp[i][col]!=dp[i-1][col]){
                    col=col-s[i].price;
                    buy[i]=1;
                }
            printf("%d\n",dp[n][m]);
            for(int i=1;i<=n;i++)
                if(buy[i]) printf("%d ",i);
            printf("\n");
        }
    }
    return 0;
}
