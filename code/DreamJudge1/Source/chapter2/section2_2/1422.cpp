#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    int m,n;
    long long tmp=0;
    char x[100];//�����M���ƴ�
    char ans[100];//N���ƴ�
    scanf("%d%d%s",&m,&n,&x);
    int xlen=strlen(x);
    for(int i=0;i<xlen;i++){//M����ת10����
        tmp*=m;
        if(x[i]>='0'&&x[i]<='9') tmp+=(x[i]-'0');
        else tmp+=(x[i]-'A'+10);
    }
    //printf("%d ",tmp);
    //10����תN����
    int cur=0;
    while(tmp!=0){
        int w=tmp%n;
        if(w<10) ans[cur++]=w+'0';
        else ans[cur++]=w-10+'a';
        tmp/=n;
    }
    for(int i=cur-1;i>=0;i--) printf("%c",ans[i]);
    return 0;
}
