#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,n;
    scanf("%d%d",&a,&n);
    long long res=0,cur=a,temp=10;
    for(int i=1;i<=n;i++){
        res+=cur;
        cur+=a*temp;
        temp*=10;//ע�ⲻҪ��pow��˷�,�о�������
    }
    printf("%lld",res);//ʹ��long long���ͣ��������
    return 0;
}
