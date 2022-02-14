#include <stdio.h>
#include <string.h>
using namespace std;

int v[1005];//v[i]��i����С������
int prime[1005];//��¼����

/*
����ŷ��ɸ��(�㷨��������ָ��P136)
�õ�[2,n]֮�������,���������ĸ���
*/
int getprime(int n){
    memset(v,0,sizeof(v));
    int m=0;//��¼�����ĸ���
    for(int i=2;i<=n;i++){
        if(v[i]==0){//��������
            v[i]=i;
            prime[m++]=i;
        }
        for(int j=0;j<m&&prime[j]*i<=n;j++)//ɸ����
            v[prime[j]*i]=prime[j];
    }
    return m;
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a>b){
            int tmp=a;
            a=b;
            b=tmp;
        }
        int m=getprime(b);
        int num=0;
        for(int i=0;i<m;i++){
            if(prime[i]>=a&&prime[i]<=b) num++;
        }
        printf("%d\n",num);
    }
    return 0;
}
