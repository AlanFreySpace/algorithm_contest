#include <stdio.h>
#include <cmath>
using namespace std;

//同模余定理应用
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int tmp=n%3;
        int tmp1=pow(tmp,5);
        int ans=tmp1%3;
        printf("%d\n",ans);
    }
}
