#include <bits/stdc++.h>
using namespace std;

//������,����123�ķ�����Ϊ321
/*
˼·:�������µ�ʽ��������
0*10+3=3 3*10+2=32 32*10+1=321
*/
int main(){
    int n,ans=0;
    scanf("%d",&n);
    while(n>0){//��n��λ�ֽ�
        ans=ans*10+n%10;
        n=n/10;
    }
    printf("%d",ans);
    return 0;
}
