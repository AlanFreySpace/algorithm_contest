#include <stdio.h>
#include <string.h>
using namespace std;

//��������s,��s%n�ĳ���
char s[1000];

int main(){
    int n;
    while(scanf("%s%d",&s,&n)!=EOF){
        int len=strlen(s);
        int m=0;
        for(int i=0;i<len;i++)
            m=((m*10)%n+(s[i]-'0')%n)%n;
        printf("%d\n",m);
    }
    return 0;
}
