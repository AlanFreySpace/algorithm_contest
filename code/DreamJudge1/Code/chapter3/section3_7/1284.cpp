#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 1e9

int nprime[1005];//nprime[i]记录n!的素因子i出现的次数
int aprime[1005];//aprime[i]记录a的素因子i出现的次数

int main(){
    int n,a;
    while(scanf("%d%d",&n,&a)!=EOF){
        memset(nprime,0,sizeof(nprime));
        memset(aprime,0,sizeof(aprime));
        for(int i=2;i<=n;i++){//求2,3,...,n的素因子
            int m=i;
            for(int j=2;j<=sqrt(m);j++){//求i的素因子
                if(m%j==0)
                    while(m%j==0){
                        nprime[j]++;
                        m/=j;
                    }
            }
            if(m>1) nprime[m]++;
        }

        for(int i=2;i<=sqrt(a);i++){//求a的素因子
            if(a%i==0)
                while(a%i==0){
                    aprime[i]++;
                    a/=i;
                }
        }
        if(a>1) aprime[a]++;

        int ans=INF;//nprime的最小者决定上限
        for(int i=0;i<1005;i++)
            if(aprime[i]!=0) ans=min(ans,nprime[i]/aprime[i]);
        printf("%d\n",ans);
    }
    return 0;
}
