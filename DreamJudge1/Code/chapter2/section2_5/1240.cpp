#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char s[105];
    while(gets(s)!=NULL){
        int len=strlen(s);
        if(s[0]>='a'&&s[0]<='z') s[0]='A'+s[0]-'a';
        for(int i=1;i<len;i++){
            if(s[i-1]==' '||s[i-1]=='\t'){//注意制表符为'\t'
                if(s[i]>='a'&&s[i]<='z') s[i]='A'+s[i]-'a';
            }
        }
        printf("%s\n",s);
    }
    return 0;
}
