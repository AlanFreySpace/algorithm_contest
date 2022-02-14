#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    char s[10];
    while(gets(s)!=NULL){
        int len=strlen(s);
        for(int i=0;i<len-1;i++)
            for(int j=i+1;j<len;j++)
                if(s[i]>s[j]){
                    char t=s[i];
                    s[i]=s[j];
                    s[j]=t;
                }
        do{
            printf("%s\n",s);
        }while(next_permutation(s,s+len));
    }
    return 0;
}
