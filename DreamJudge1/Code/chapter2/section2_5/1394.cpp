#include <stdio.h>
#include <string.h>
using namespace std;

/*
ע��������������:
hello how are you you oooo .
*/
int main(){
    char s[200];
    while(gets(s)!=NULL){
        int len=strlen(s);
        int before=0,after=0;//before��after��ʶһ�����ʵĿ�ʼ�ͽ���
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
