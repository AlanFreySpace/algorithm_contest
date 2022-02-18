#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
/*
w�������Ʒ����,dp�ǹ�������,dp[i]��ʾ�ڸù�������,�����ܷ����÷�������
Ϊi����Ʒ
*/
int w[105],dp[1005];

int main(){
    int s,n;
    while(scanf("%d%d",&s,&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++)
            for(int j=s;j>=w[i];j--)
                dp[j]=max(dp[j-w[i]],dp[j]);
        if(dp[s]==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
