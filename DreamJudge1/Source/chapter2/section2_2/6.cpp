#include <stdio.h>
#include <string.h>
using namespace std;

/*
x����תy����,ʵ�����Ƕ�ǰ����ѧ֪ʶ���ۺ�,ֻ��:
�Ƚ�x����ת��Ϊ10����,�ٽ�ʮ����ת��Ϊy����
*/
int main(){
    char s[105];//x���ƴ�
    int x,y;//x����,y����
    scanf("%s%d%d",&s,&x,&y);
    int len=strlen(s);
    int tmp=0;//ת��Ϊ10���ƺ�Ľ��
    for(int i=0;i<len;i++){
        tmp*=x;
        if(s[i]>='0'&&s[i]<='9')
            tmp+=(s[i]-'0');
        else tmp+=(s[i]-'A'+10);
    }
    char ans[105];//�洢tmpת���ɵ�y���ƴ�
    int cur=0,w;
    while(tmp!=0){
        w=tmp%y;
        if(w<10) ans[cur++]=w+'0';
        else ans[cur++]=w-10+'A';
        tmp/=y;
    }
    for(int i=cur-1;i>=0;i--) printf("%c",ans[i]);
    return 0;
}
