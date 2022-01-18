#include <stdio.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans[50]={0};
        int cur=0;
        if(n==0) printf("%d\n",0);
        else{
            while(n!=0){
                ans[cur++]=n%2;
                n/=2;
            }
            for(int i=cur-1;i>=0;i--) printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
