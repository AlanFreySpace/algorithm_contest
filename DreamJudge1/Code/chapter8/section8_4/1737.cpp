#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[1005];
//ע�Ȿ��Ҫ����������,������ʵ����dp��
int main(){
    while(scanf("%d",&n)!=EOF){
        int ans=0,j;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++){
            for(j=i;j<n;j++)
                if(a[j]>a[j+1]){
                    ans=max(ans,a[j]-a[i]);
                    break;
                }
            i=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}
