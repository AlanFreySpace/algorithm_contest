#include <stdio.h>
using namespace std;

int main(){//��������Է��ִ�������1413���ģ��
    int n;
    while(scanf("%d",&n)!=EOF){
        int a[25]={0};
        a[1]=2,a[2]=3;
        for(int i=3;i<=n;i++) a[i]=a[i-1]+a[i-2];
        printf("%d\n",a[n]);
    }
    return 0;
}
