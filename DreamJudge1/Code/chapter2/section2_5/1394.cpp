#include <stdio.h>
#include <string.h>
using namespace std;

/*
注意有这样的样例:
hello how are you you oooo .
*/
int main(){
    char s[200];
    while(gets(s)!=NULL){
        int len=strlen(s);
        int before=0,after=0;//before和after标识一个单词的开始和结束
        for(int i=1;i<len;i++){
            if(s[i]!=' '&&s[i-1]==' ') before=i;
            if((s[i]==' '&&s[i-1]!=' ')||s[i]=='.'){
                after=i;
                if(after-before!=0)
                    printf("%d ",after-before);
            }
        }
        printf("\n");
    }
    return 0;
}
