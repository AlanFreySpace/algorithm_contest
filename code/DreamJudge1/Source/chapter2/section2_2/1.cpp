#include <bits/stdc++.h>
using namespace std;

//求反序数,例如123的反序数为321
/*
思路:根据以下等式看出规律
0*10+3=3 3*10+2=32 32*10+1=321
*/
int main(){
    int n,ans=0;
    scanf("%d",&n);
    while(n>0){//将n逐位分解
        ans=ans*10+n%10;
        n=n/10;
    }
    printf("%d",ans);
    return 0;
}
