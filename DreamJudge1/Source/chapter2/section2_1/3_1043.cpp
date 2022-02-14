#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,n;
    scanf("%d%d",&a,&n);
    long long res=0,cur=a,temp=10;
    for(int i=1;i<=n;i++){
        res+=cur;
        cur+=a*temp;
        temp*=10;//注意不要用pow算乘方,有精度问题
    }
    printf("%lld",res);//使用long long类型，避免溢出
    return 0;
}
