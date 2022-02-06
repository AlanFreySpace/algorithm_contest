#include <stdio.h>
using namespace std;

//4*ABCD=DCBA
int main(){
    for(int i=1;i<=2;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int m=0;m<=9;m++){
                    int a=m+k*10+j*100+i*1000;
                    int b=i+j*10+k*100+m*1000;
                    if(4*a==b) printf("%d\n",a);
                }
            }
        }
    }
    return 0;
}
