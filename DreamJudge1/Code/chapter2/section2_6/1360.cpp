#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    char s[205];
    while(scanf("%s",&s)!=EOF){
        int len=strlen(s);
        sort(s,s+len);
        printf("%s\n",s);
    }
    return 0;
}
