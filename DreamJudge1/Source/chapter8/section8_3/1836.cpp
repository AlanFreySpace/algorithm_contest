#include <stdio.h>
#include <string.h>
using namespace std;
/*
dp[i]:��¼��a[i]��β����ݼ������еĳ���
pre[i]:��¼��a[i]��β����ݼ���������ͨ��֮ǰ���ĸ���ݼ�������
������(����¼��a[i]��β����ݼ���������a[i]֮ǰ�Ǹ�Ԫ�ص���)
*/
int n;
int a[105],dp[105],pre[105],ans[105];

int LDS(){
    int index=0,len=0;
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++)
            if(a[j]>a[i]&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                pre[i]=j;
            }
        if(dp[i]>len){
            len=dp[i];
            index=i;
        }
    }
    return index;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int index=LDS(),len=0;
        while(index){
            ans[len++]=index;
            index=pre[index];
        }
        for(int i=len-1;i>=0;i--) printf("%d ",a[ans[i]]);
        printf("\n");
    }
    return 0;
}
