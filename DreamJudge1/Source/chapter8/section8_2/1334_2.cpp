#include <stdio.h>
using namespace std;

int dp[10005],a[10005];

//s用于记录以a[i]结尾的最大连续子序列的起始元素
int main(){
    int k;
    while(scanf("%d",&k)!=EOF){
        if(k==0) break;
        for(int i=0;i<k;i++) scanf("%d",&a[i]);
        for(int i=0;i<k;i++) dp[i]=a[i];
        int s=a[0],first=a[0],last=a[0],ans=a[0];
        for(int i=1;i<k;i++){
            if(dp[i-1]>0) dp[i]+=dp[i-1];
            else if(dp[i-1]<0) s=a[i];
            if(dp[i]>ans){
                ans=dp[i];
                last=a[i];
                first=s;
            }
        }
        if(ans<0) printf("%d %d %d\n",0,a[0],a[k-1]);
        else if(ans==0) printf("0 0 0\n");
        else printf("%d %d %d\n",ans,first,last);
    }
    return 0;
}
