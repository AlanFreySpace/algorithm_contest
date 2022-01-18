#include <bits/stdc++.h>
using namespace std;

/*
十进制转x进制(其中0<x<10),使用短除法实现
例如十进制68=二进制1000100
*/
int main(){
    int n,x;//十进制n转为x进制
    scanf("%d%d",&n,&x);
    int ans[105];//存储转换后的答案
    int cur=0;
    while(n!=0){//模拟短除法过程
        ans[cur++]=n%x;
        n/=x;
    }
    for(int i=cur-1;i>=0;i--) printf("%d",ans[i]);//倒序输出余数
    return 0;
}
