#include <stdio.h>
using namespace std;

#define ll long long

/*
计算:(x^n)%m,利用快速幂取模,参考算法竞赛入门到进阶P157
注意快速幂与快速幂取模的差别仅在于每步运算后是否取模
*/
int fastmod(int x,int n,int m){
    ll base=x;
    ll res=1;
    while(n){
        if(n&1) res=(res*base)%m;
        base=(base*base)%m;
        n>>=1;
    }
    return res;
}

int main(){
    int x,n;
    while(scanf("%d%d",&x,&n)!=EOF)
        printf("%d\n",fastmod(x,n,233333));
    return 0;
}
