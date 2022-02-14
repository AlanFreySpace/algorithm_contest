#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char s[105];
    while(gets(s)!=NULL){
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]>='A'&&s[i]<='Z')
                s[i]='A'+(s[i]-'A'+3)%26;
            else if(s[i]>='a'&&s[i]<='z')
                s[i]='a'+(s[i]-'a'+3)%26;
        }
        printf(s);
    }
    return 0;
}
