#include <algorithm>
#include <stdio.h>
using namespace std;

/*
C++ STL:
sort()����:
���δ�����������,��:
Ҫ�����������㣬Ҫ����������յ�+1���ȽϺ�����
�ȽϺ������Բ����Ĭ��Ϊ��С��������
�ȽϺ�����ʹ�òο�:
https://baike.baidu.com/item/sort%E5%87%BD%E6%95%B0/11042699
*/

int a[100];
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    sort(a,a+N);
    for(int i=0;i<N;i++) printf("%d ",a[i]);
    return 0;
}
