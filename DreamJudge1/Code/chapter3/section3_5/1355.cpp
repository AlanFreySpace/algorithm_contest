#include <stdio.h>
#include <math.h>
using namespace std;

//与1013题的思路相同
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n<=1) printf("no\n");
        else{
            int flag=0;
            for(int i=2;i<=sqrt(n);i++){
                if(n%i==0){
                    printf("no\n");
                    flag=1;
                    break;
                }
            }
            if(flag==0) printf("yes\n");
        }
    }
    return 0;
}
