#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char s[105];
    while(gets(s)!=NULL){
        char a[105]={'\0'};//³õÊ¼»¯´®Îª¿Õ
        char b[105]={'\0'};
        int len=strlen(s),len1=0,len2=0;
        for(int i=0;i<len;i++){
            if(s[i]>='0'&&s[i]<='9') b[len2++]=s[i];
            else a[len1++]=s[i];
        }
        printf("%s%s",a,b);
    }
    return 0;
}
