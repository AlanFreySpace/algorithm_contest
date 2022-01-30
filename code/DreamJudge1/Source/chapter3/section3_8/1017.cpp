#include <stdio.h>
using namespace std;

#define ll long long

/*
����:(x^n)%m,���ÿ�����ȡģ,�ο��㷨�������ŵ�����P157
ע��������������ȡģ�Ĳ�������ÿ��������Ƿ�ȡģ
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
