#include <stdio.h>
#include <algorithm>
using namespace std;

int a[10005];
int n;

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int j,ans=0;
        for(int i=0;i<n;i++){
            for(j=i;j<n;j++)
                if(a[j]+1!=a[j+1]) break;
            ans=max(ans,j-i+1);
            i=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
