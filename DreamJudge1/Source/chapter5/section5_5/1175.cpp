#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    int l,m;
    while(scanf("%d%d",&l,&m)!=EOF){
        int road[10005]={0};
        int sum=l+1,left,right;
        for(int i=0;i<=l;i++) road[i]=1;
        for(int i=0;i<m;i++){
            scanf("%d%d",&left,&right);
            for(int j=left;j<=right;j++){
                if(road[j]==1){
                    road[j]=0;
                    sum--;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
