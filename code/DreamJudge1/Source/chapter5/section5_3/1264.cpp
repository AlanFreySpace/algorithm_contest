#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF){
        int ans=0,tmp=1;
        while(m<n){//���������Ҳ���
            ans+=tmp;
            tmp*=2;
            m=2*m+1;
        }
        int h1=log(m)/log(2),h2=log(n)/log(2);
        if(h1==h2){//������nͬһ��,ans��Ҫ�ټ�Щ��
            if(m==n) ans+=tmp;
            else ans+=(tmp+n-m);
        }
        printf("%d\n",ans);
    }
    return 0;
}
