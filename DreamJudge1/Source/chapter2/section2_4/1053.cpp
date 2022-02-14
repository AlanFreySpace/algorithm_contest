#include <stdio.h>
using namespace std;

int main(){
    int n,hour,minute;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d:%d",&hour,&minute);
        hour+=13;
        minute+=15;
        hour+=(minute/60);
        minute%=60;
        hour%=24;
        printf("%d:%d\n",hour,minute);
    }
    return 0;
}
