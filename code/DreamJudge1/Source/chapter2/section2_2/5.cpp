#include <stdio.h>
#include <string.h>
using namespace std;

/*
x����תʮ����,˼·�Ͷ�����תʮ���������Ƶ�
*/
int main(){
    char s[105];//x���ƴ�
    int x;//x����
    scanf("%s%d",&s,&x);
    int n=strlen(s);
    int ans=0;
    for(int i=0;i<n;i++){
        ans*=x;//��λ
        //���ϸ�λ�ϵ�ֵ
        if(s[i]>='0'&&s[i]<='9')
            ans+=(s[i]-'0');
        else ans+=(s[i]-'A'+10);
    }
    printf("%d",ans);
    return 0;
}
