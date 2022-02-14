#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s1[300];
char s2[300];

bool cmp(char a,char b){//不区分大小写对英文字母排序
    if(a>='A'&&a<='Z') a='a'+(a-'A');
    if(b>='A'&&b<='Z') b='a'+(b-'A');
    return a<b;
}

int main(){
    while(gets(s1)!=NULL){
        int cur=0,len=strlen(s1);
        for(int i=0;i<len;i++){//英文字母单独取出进行stableSort
            if((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z'))
                s2[cur++]=s1[i];
        }
        stable_sort(s2,s2+cur,cmp);
        cur=0;
        for(int i=0;i<len;i++){//排序部分与不参与排序的部分进行组装
            if((s1[i]>='a'&&s1[i]<='z')||(s1[i]>='A'&&s1[i]<='Z'))
                printf("%c",s2[cur++]);
            else printf("%c",s1[i]);
        }
        printf("\n");
    }
    return 0;
}
