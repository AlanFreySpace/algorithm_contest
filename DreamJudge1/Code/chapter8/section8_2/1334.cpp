#include <stdio.h>
#include <string.h>
using namespace std;

/*
方法一:在完成dp后找到首元素,这种方法要特别注意
边界条件的处理,index=0和index>=0这一条件都是为
1
10这一用例所设
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
