#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

/*
ע��Ӧ���ַ���a��b��ת����,��������Ϊ�����ó˻��ĸ�λ
�ز�Ϊ0������,���ڴ�ӡ�ַ���
res�ĵ�λ�����ֵĵ�λ,��λ�����ֵĸ�λ
*/
int main(){
    int n;
    string a,b;
    int res[210]={0};//��res����Ԫ�س�ʼ��Ϊ0
    cin>>n>>a>>b;
    reverse(a.begin(),a.end());//��ת�ַ���
    reverse(b.begin(),b.end());
    for(int i=0;i<n;i++){//����
        for(int j=0;j<n;j++)
            res[i+j]+=(a[i]-'0')*(b[j]-'0');
    }
    for(int i=0;i<2*n-1;i++){//��λ
        if(res[i]>9){
            res[i+1]+=(res[i]/10);
            res[i]%=10;
        }
    }
    int flag=209;
    while(true){
        if(res[flag]!=0) break;
        flag--;
    }
    //printf("%d",flag);
    for(int i=flag;i>=0;i--) printf("%d",res[i]);
    return 0;
}
