#include <stdio.h>
using namespace std;

int main(){
    int a,b;
    for(int i=0;i<=5;i++){
        for(int j=0;j<=5;j++){
            for(int k=0;k<=9;k++){
               a=100*i+10*j+k;
               b=100*j+10*k+k;
               if(a+b==532) printf("%d %d %d\n",i,j,k);
            }
        }
    }
    return 0;
}
