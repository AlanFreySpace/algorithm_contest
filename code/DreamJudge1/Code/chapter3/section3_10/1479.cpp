#include <stdio.h>
using namespace std;

/*
��HDU 5686������һ����
������Ҫ��f[n]ʱ�����Կ���Ϊǰn-1��0�ּ���һ��0 ��
���������:����ʹ�õ�n��0���кϲ�ʱ,����f[n-1]������
��ʹ�����0���кϲ�ʱ������f[n-2]������
����f[n]=f[n-1]+f[n-2]
*/
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int f1=1,f2=1,ans=0;
        for(int i=2;i<=n;i++){
            ans=(f1+f2)%2333333;
            f1=f2;
            f2=ans;
        }
        if(n==1) printf("1\n");
        else printf("%d\n",ans);
    }
}
