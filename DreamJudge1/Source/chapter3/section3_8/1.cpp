#include <stdio.h>
using namespace std;

//快速幂:计算a^n 利用位运算加速 参考算法竞赛入门到进阶P156
int fastpow(int a,int n){
    int base=a,ans=1;
    while(n){
        if(n&1) ans*=base;
        base*=base;
        n>>=1;
    }
    return ans;
}

int main(){
    int a,n;
    while(scanf("%d%d",&a,&n)!=EOF)
        printf("%d\n",fastpow(a,n));
    return 0;
}
