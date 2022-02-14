#include <stdio.h>
using namespace std;

int main(){//简单的等差数列求和题
    int n,a,ans;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            ans=2*(a-1)*(a-1)+2*a-1;
            printf("%d\n",ans);
        }
    }
    return 0;
}
