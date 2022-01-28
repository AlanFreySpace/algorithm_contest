#include <stdio.h>
using namespace std;

//���ص�Fibonacci������
//��ӡ��Fibonacci���е�ǰn��
void fibonacci(int n){
    if(n==0) printf("0\n");
    else{
        int a1=0,a2=1;
        printf("0 1 ");
        for(int i=2;i<=n;i++){
            int tmp=a1+a2;
            printf("%d ",tmp);
            a1=a2;
            a2=tmp;
        }
        printf("\n");
    }
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF) fibonacci(n);
    return 0;
}
