#include <stdio.h>
#include <string.h>
using namespace std;

/*
������תʮ����
*/
int main(){
    char s[105];//���ڴ洢�����ƴ�
    scanf("%s",&s);
    int n=strlen(s);
    int ans=0;//תΪʮ���ƵĽ��
    for(int i=0;i<n;i++){//�Ӷ��������ĸ�λ��ʼת��
        if(s[i]=='0') ans*=2;//��0���2
        else ans=ans*2+1;//��1���2��1
    }
    printf("%d",ans);
    return 0;
}
