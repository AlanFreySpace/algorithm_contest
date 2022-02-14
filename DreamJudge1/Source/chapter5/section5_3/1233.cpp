#include <stdio.h>
using namespace std;

int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF){
        while(true){
            if(x<y) y>>=1;
            else if(x>y) x>>=1;
            else{
                printf("%d\n",x);
                break;
            }
        }
    }
    return 0;
}
