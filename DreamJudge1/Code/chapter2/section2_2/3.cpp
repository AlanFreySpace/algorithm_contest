#include <bits/stdc++.h>
using namespace std;

/*
十进制转x进制(通用版,即只需x>0),使用短除法实现
此时只需再考虑大于9的数字如何用字符表示出即可
例如十进制10=十六进制A
*/
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    char ans[105];
    int cur=0;
    int w=0;//表示当前余数
    while(n!=0){//模拟短除法过程
        w=n%x;
        if(w<10) ans[cur++]=w+'0';
        else ans[cur++]=w-10+'A';
        n/=x;
    }
    for(int i=cur-1;i>=0;i--) printf("%c",ans[i]);//倒序输出余数
    return 0;
}
