#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define INF 1e9;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        char s[105]="";
        for(int i=0;i<n;i++){
            scanf("%s",&s);
            int len=strlen(s);
            int m=0;
            for(int i=0;i<len;i++)//提取整数
                if(s[i]>='0'&&s[i]<='9')
                    m=m*10+s[i]-'0';

            int ans=0;//提取最大素因子
            for(int i=2;i<=sqrt(m);i++){
                if(m%i==0){
                    ans=max(ans,i);
                    while(m%i==0) m/=i;
                }
            }
            if(m>1) ans=max(ans,m);
            printf("%d\n",ans);
        }
    }
    return 0;
}
