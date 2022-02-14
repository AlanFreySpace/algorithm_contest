#include <stdio.h>
#include <string.h>
using namespace std;

/*
x进制转十进制,思路和二进制转十进制是类似的
*/
int main(){
    char s[105];//x进制串
    int x;//x进制
    scanf("%s%d",&s,&x);
    int n=strlen(s);
    int ans=0;
    for(int i=0;i<n;i++){
        ans*=x;//进位
        //加上该位上的值
        if(s[i]>='0'&&s[i]<='9')
            ans+=(s[i]-'0');
        else ans+=(s[i]-'A'+10);
    }
    printf("%d",ans);
    return 0;
}
