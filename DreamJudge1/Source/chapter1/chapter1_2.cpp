#include <stdio.h>
using namespace std;

/*
���� N��N<=100����������ÿ�����ķ�Χ> 0 ���� <= 100���뽫ÿ����ͬ������С������������������Ӧ�ĸ�����
�������� 8                          ������� 1 2
         3 2 2 1 1 4 5 5                     2 2
                                             3 1
                                             4 1
                                             5 2
*/

int f[101];//ע��int�����ʼ����������Ԫ�ؾ�Ϊ0
int main(){
    int N;
    scanf("%d",&N);
    int num;
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        f[num]++;
    }
    for(int i=1;i<=100;i++){
        if(f[i]>0) printf("%d %d\n",i,f[i]);
    }
    return 0;
}
