#include <stdio.h>
using namespace std;
//����catalan�� �ο����¾�177ҳ
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        long long ans=1;
        for(int i=1;i<=n;i++)
            ans=(4*i-2)*ans/(i+1);
        printf("%lld\n",ans);
    }
    return 0;
}
