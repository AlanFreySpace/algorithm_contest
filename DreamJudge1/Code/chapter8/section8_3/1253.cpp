#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[105],dp1[105],dp2[105];

//dp1[i]表示以a[i]结尾的最长递增子序列的长度
void LIS(){
    for(int i=0;i<n;i++){
        dp1[i]=1;
        for(int j=0;j<i;j++)
            if(a[j]<a[i]) dp1[i]=max(dp1[i],dp1[j]+1);
    }
}
//dp2[i]表示以a[i]开头的最长递减子序列的长度
void LDS(){
    for(int i=n-1;i>=0;i--){
        dp2[i]=1;
        for(int j=n-1;j>i;j--)
            if(a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+1);
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        LIS();
        LDS();
        int k=0;
        for(int i=0;i<n;i++) k=max(k,dp1[i]+dp2[i]);
        int ans=n-k+1;
        printf("%d\n",ans);
    }
    return 0;
}
