#include <stdio.h>
using namespace std;

//dp[i]代表以a[i]结尾的最大连续子序列的和
int k;
int a[100005],dp[100005];
//本题与8.2节1334题几乎完全一样
int main(){
    while(scanf("%d",&k)!=EOF){
        for(int i=0;i<k;i++) scanf("%d",&a[i]);
        int ans=a[0],first=0,last=0,s=0;
        dp[0]=a[0];
        for(int i=1;i<k;i++){
            dp[i]=a[i];
            if(dp[i-1]>0) dp[i]+=dp[i-1];
            else if(dp[i-1]<0) s=i;
            if(ans<dp[i]){
                ans=dp[i];
                last=i;
                first=s;
            }
        }
        if(ans<0) printf("0 0 0\n");
        else printf("%d %d %d\n",ans,first,last);
    }
    return 0;
}
