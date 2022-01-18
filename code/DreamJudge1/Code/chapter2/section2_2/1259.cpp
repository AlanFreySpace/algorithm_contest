#include <stdio.h>
#include <string.h>
using namespace std;

int main(){//本题数据范围不大,无需高精度计算
    char s[50];
    while(scanf("%s",&s)!=EOF){
        int len=strlen(s);
        long long ans=0;
        for(int i=2;i<len;i++){
            ans*=16;
            if(s[i]>='0'&&s[i]<='9') ans+=(s[i]-'0');
            else ans+=(s[i]-'A'+10);
        }
        printf("%lld",ans);
    }
    return 0;
}
