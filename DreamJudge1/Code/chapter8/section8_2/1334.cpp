#include <stdio.h>
#include <string.h>
using namespace std;

/*
����һ:�����dp���ҵ���Ԫ��,���ַ���Ҫ�ر�ע��
�߽������Ĵ���,index=0��index>=0��һ��������Ϊ
1
10��һ��������
*/
int a[10005],dp[10005],num;

int main(){
    int k;
    while(scanf("%d",&k)!=EOF){
        if(k==0) break;
        for(int i=0;i<k;i++) scanf("%d",&a[i]);
        for(int i=0;i<k;i++) dp[i]=a[i];
        int ans=a[0],last=a[0],first,index=0;
        for(int i=1;i<k;i++){
            if(dp[i-1]>0) dp[i]+=dp[i-1];
            if(dp[i]>ans){
                ans=dp[i];
                last=a[i];
                index=i;
            }
        }
        if(ans<0) printf("%d %d %d\n",0,a[0],a[k-1]);
        else if(ans==0) printf("0 0 0\n");
        else{
            int sum=ans;
            while(sum!=0) sum-=a[index--];
            if(index>=0&&a[index]==0) first=0;
            else first=a[index+1];
            printf("%d %d %d\n",ans,first,last);
        }
    }
    return 0;
}
