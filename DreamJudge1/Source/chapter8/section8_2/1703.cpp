#include <stdio.h>
using namespace std;

int a[105],dp[105];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) dp[i]=a[i];
        int ans=a[0],s=0,first=0,last=0;
        for(int i=1;i<n;i++){
            if(dp[i-1]>0) dp[i]+=dp[i-1];
            if(dp[i-1]<0) s=i;
            if(dp[i]>ans){
                ans=dp[i];
                first=s;
                last=i;
            }
        }
        for(int i=first;i<=last;i++) printf("%d ",a[i]);
        printf("\n");
        printf("%d\n",ans);
    }
    return 0;
}
