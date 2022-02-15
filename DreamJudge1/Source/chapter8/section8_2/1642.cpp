#include <stdio.h>
#include <string.h>
using namespace std;

int dp[10000005];
char s[10000005];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",&s);
        int ans=0,num=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') dp[i]=1;
            else if(s[i]=='1'){
                dp[i]=-1;
                num++;//统计原01串中1的个数
            }
            if(dp[i]>ans) ans=dp[i];
            if(i>0){
                if(dp[i-1]>0) dp[i]+=dp[i-1];
                if(dp[i]>ans) ans=dp[i];
            }
        }
        printf("%d\n",ans+num);
    }
    return 0;
}
