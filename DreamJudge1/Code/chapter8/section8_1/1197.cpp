#include <stdio.h>
using namespace std;

int main(){//�����1413��˼·һģһ��
    int n;
    while(scanf("%d",&n)!=EOF){
        int a[25]={0};
        a[1]=1,a[2]=2;
        for(int i=3;i<=n;i++) a[i]=a[i-1]+a[i-2];
        printf("%d\n",a[n]);
    }
    return 0;
}
