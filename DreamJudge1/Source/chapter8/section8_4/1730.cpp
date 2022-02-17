#include <stdio.h>
#include <string.h>
using namespace std;

char a[105],b[105],s[105];
int dp[105][105];

//dp[i][j]表示以a[i-1]结尾和以b[j-1]结尾的连续公共子序列的长度
int main(){
    while(scanf("%s%s",&a,&b)!=EOF){
        int len=0,index=0;
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        int alen=strlen(a),blen=strlen(b);
        for(int i=1;i<=alen;i++)
            for(int j=1;j<=blen;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    if(dp[i][j]>=len){
                        len=dp[i][j];
                        index=i-1;
                    }
                }
            }
        for(int i=len-1;i>=0;i--) s[i]=a[index--];
        printf("%d\n%s\n",len,s);
    }
    return 0;
}
