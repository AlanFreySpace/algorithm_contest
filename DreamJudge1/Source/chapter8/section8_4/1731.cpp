#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char a[1005],b[1005];
int dp[1005][1005];

int main(){
    while(scanf("%s%s",&a,&b)!=EOF){
        memset(dp,0,sizeof(dp));
        int alen=strlen(a),blen=strlen(b);
        for(int i=1;i<=alen;i++)
            for(int j=1;j<=blen;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        printf("%d\n",dp[alen][blen]);
    }
    return 0;
}
