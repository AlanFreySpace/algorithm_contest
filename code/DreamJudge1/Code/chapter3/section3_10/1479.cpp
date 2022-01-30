#include <stdio.h>
using namespace std;

/*
与HDU 5686那题是一样的
当我们要求f[n]时，可以考虑为前n-1个0又加了一个0 。
有两种情况:当不使用第n个0进行合并时,就有f[n-1]个序列
当使用这个0进行合并时，就有f[n-2]个序列
所以f[n]=f[n-1]+f[n-2]
*/
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int f1=1,f2=1,ans=0;
        for(int i=2;i<=n;i++){
            ans=(f1+f2)%2333333;
            f1=f2;
            f2=ans;
        }
        if(n==1) printf("1\n");
        else printf("%d\n",ans);
    }
}
