#include <stdio.h>
#include <math.h>
using namespace std;

//�ο��㷨��������ָ��137ҳ
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        for(int i=2;i<=sqrt(n);i++){//ע��n�ǲ��ϱ仯��
            if(n%i==0)
                while(n%i==0){
                    ans++;
                    n/=i;
                }
        }
        if(n>1) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
