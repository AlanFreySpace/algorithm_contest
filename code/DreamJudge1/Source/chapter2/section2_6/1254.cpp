#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s[21];

int main(){
    while(scanf("%s",&s)!=EOF){
        int len=strlen(s);
        sort(s,s+len);
        for(int i=0;i<len;i++) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
