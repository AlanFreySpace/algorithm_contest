#include <stdio.h>
#include <string.h>
using namespace std;

/*
二进制转十进制
*/
int main(){
    char s[105];//用于存储二进制串
    scanf("%s",&s);
    int n=strlen(s);
    int ans=0;//转为十进制的结果
    for(int i=0;i<n;i++){//从二进制数的高位开始转换
        if(s[i]=='0') ans*=2;//逢0则进2
        else ans=ans*2+1;//逢1则进2加1
    }
    printf("%d",ans);
    return 0;
}
