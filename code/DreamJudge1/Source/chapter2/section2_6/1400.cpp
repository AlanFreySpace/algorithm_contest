#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int a[1005];
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        if(n-1>0){
            printf("%d\n",a[n-1]);
            for(int i=0;i<n-1;i++) printf("%d ",a[i]);
            printf("\n");
        }
        else printf("%d\n",-1);
    }
    return 0;
}
