#include <stdio.h>
#include <math.h>
using namespace std;

//ע��sqrt���ص���double����
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==1) n++;
        for(int i=n;;i++){//�ж�i�Ƿ�������
            int flag=0;
            for(int j=2;j<=sqrt(i);j++){//��i���ܵ�������һ��̽
                if(i%j==0){//i�Ǻ���
                    flag=1;
                    break;
                }
            }
            if(flag==0){//i������
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
