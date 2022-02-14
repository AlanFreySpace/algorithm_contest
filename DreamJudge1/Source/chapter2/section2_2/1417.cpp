#include <stdio.h>
using namespace std;

int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        int ans[10]={0};
        if(N==0) printf("%d\n",0);
        else{
            int cur=0;
            while(N!=0){
                ans[cur++]=N%8;
                N/=8;
            }
            for(int i=cur-1;i>=0;i--) printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
