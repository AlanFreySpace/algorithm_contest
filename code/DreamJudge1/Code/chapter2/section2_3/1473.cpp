#include <stdio.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){//��ӡ���ε��ϰ벿��
        for(int j=n-i;j>1;j--) printf(" ");
        for(int j=0;j<2*i+1;j++) printf("*");
        printf("\n");
    }
    for(int i=1;i<n;i++){//��ӡ���ε��°벿��
        for(int j=i;j>0;j--) printf(" ");
        for(int j=0;j<2*(n-i-1)+1;j++) printf("*");
        printf("\n");
    }
    return 0;
}
