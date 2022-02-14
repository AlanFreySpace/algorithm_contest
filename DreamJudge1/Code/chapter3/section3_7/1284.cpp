#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 1e9

int nprime[1005];//nprime[i]��¼n!��������i���ֵĴ���
int aprime[1005];//aprime[i]��¼a��������i���ֵĴ���

int main(){
    int n,a;
    while(scanf("%d%d",&n,&a)!=EOF){
        memset(nprime,0,sizeof(nprime));
        memset(aprime,0,sizeof(aprime));
        for(int i=2;i<=n;i++){//��2,3,...,n��������
            int m=i;
            for(int j=2;j<=sqrt(m);j++){//��i��������
                if(m%j==0)
                    while(m%j==0){
                        nprime[j]++;
                        m/=j;
                    }
            }
            if(m>1) nprime[m]++;
        }

        for(int i=2;i<=sqrt(a);i++){//��a��������
            if(a%i==0)
                while(a%i==0){
                    aprime[i]++;
                    a/=i;
                }
        }
        if(a>1) aprime[a]++;

        int ans=INF;//nprime����С�߾�������
        for(int i=0;i<1005;i++)
            if(aprime[i]!=0) ans=min(ans,nprime[i]/aprime[i]);
        printf("%d\n",ans);
    }
    return 0;
}
