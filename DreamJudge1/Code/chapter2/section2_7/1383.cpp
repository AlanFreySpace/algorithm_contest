#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1000];

int main(){
    int n,k;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        scanf("%d",&k);
        sort(a,a+n);
        int tmp=1,index;//表明当前数字是第几大
        if(k==1) printf("%d\n",a[0]);
        else{
            for(int i=1;i<n;i++){
                if(a[i]!=a[i-1]) tmp++;
                if(tmp==k){
                    index=i;
                    break;
                }
            }
            printf("%d\n",a[index]);
        }
    }
    return 0;
}
