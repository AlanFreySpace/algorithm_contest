#include <bits/stdc++.h>
using namespace std;

/*
ʮ����תx����(ͨ�ð�,��ֻ��x>0),ʹ�ö̳���ʵ��
��ʱֻ���ٿ��Ǵ���9������������ַ���ʾ������
����ʮ����10=ʮ������A
*/
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    char ans[105];
    int cur=0;
    int w=0;//��ʾ��ǰ����
    while(n!=0){//ģ��̳�������
        w=n%x;
        if(w<10) ans[cur++]=w+'0';
        else ans[cur++]=w-10+'A';
        n/=x;
    }
    for(int i=cur-1;i>=0;i--) printf("%c",ans[i]);//�����������
    return 0;
}
