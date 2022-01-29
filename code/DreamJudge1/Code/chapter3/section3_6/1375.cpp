#include <stdio.h>
#include <string.h>
using namespace std;

int v[10005],prime[10005];
//Å·À­É¸·¨
int getprime(int n){
    memset(v,0,sizeof(v));
    int m=0;
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            v[i]=i;
            prime[m++]=i;
        }
        for(int j=0;j<m&&prime[j]*i<=n;j++)
            v[prime[j]*i]=prime[j];
    }
    return m;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int m=getprime(n-1);
        int num=0;
        for(int i=0;i<m;i++){
            if(prime[i]%10==1){
                num++;
                printf("%d ",prime[i]);
            }
        }
        if(num==0) printf("-1");
        printf("\n");
    }
    return 0;
}
