#include <stdio.h>
#include <string.h>
using namespace std;

/*
x进制转y进制,实际上是对前面所学知识的综合,只需:
先将x进制转换为10进制,再将十进制转换为y进制
*/
int main(){
    char s[105];//x进制串
    int x,y;//x进制,y进制
    scanf("%s%d%d",&s,&x,&y);
    int len=strlen(s);
    int tmp=0;//转化为10进制后的结果
    for(int i=0;i<len;i++){
        tmp*=x;
        if(s[i]>='0'&&s[i]<='9')
            tmp+=(s[i]-'0');
        else tmp+=(s[i]-'A'+10);
    }
    char ans[105];//存储tmp转化成的y进制串
    int cur=0,w;
    while(tmp!=0){
        w=tmp%y;
        if(w<10) ans[cur++]=w+'0';
        else ans[cur++]=w-10+'A';
        tmp/=y;
    }
    for(int i=cur-1;i>=0;i--) printf("%c",ans[i]);
    return 0;
}
