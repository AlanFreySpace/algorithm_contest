#include <bits/stdc++.h>
using namespace std;

/*
ʮ����תx����(����0<x<10),ʹ�ö̳���ʵ��
����ʮ����68=������1000100
*/
int main(){
    int n,x;//ʮ����nתΪx����
    scanf("%d%d",&n,&x);
    int ans[105];//�洢ת����Ĵ�
    int cur=0;
    while(n!=0){//ģ��̳�������
        ans[cur++]=n%x;
        n/=x;
    }
    for(int i=cur-1;i>=0;i--) printf("%d",ans[i]);//�����������
    return 0;
}
