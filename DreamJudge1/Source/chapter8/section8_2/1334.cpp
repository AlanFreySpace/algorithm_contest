#include <stdio.h>
#include <string.h>
using namespace std;

int dp[10005],num;

int main(){
    int k;
    while(scanf("%d",&k)!=EOF){
        if(k==0) break;
        scanf("%d",&dp[0]);
        int ans=dp[0],first=dp[0],last=dp[0],record1=dp[0],record2=dp[0];
        for(int i=1;i<k-1;i++){
            scanf("%d",&num);
            if(dp[i-1]>0) dp[i]=num+dp[i-1];
            if(ans<dp[i]){
                ans=dp[i];
                last=num;
            }
        }
    }
    return 0;
}
