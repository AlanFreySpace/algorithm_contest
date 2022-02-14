#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    char s[200];
    while(gets(s)!=NULL){
        int ans[26]={0};
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]>='A'&&s[i]<='Z') ans[s[i]-'A']++;
        }
        for(int i=0;i<26;i++) printf("%c:%d\n",'A'+i,ans[i]);
    }
    return 0;
}
