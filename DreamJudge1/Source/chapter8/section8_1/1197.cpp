#include <stdio.h>
using namespace std;

int main(){//本题和1413题思路一模一样
    int n;
    while(scanf("%d",&n)!=EOF){
        int a[25]={0};
        a[1]=1,a[2]=2;
        for(int i=3;i<=n;i++) a[i]=a[i-1]+a[i-2];
        printf("%d\n",a[n]);
    }
    return 0;
}
