#include <stdio.h>
#include <algorithm>
using namespace std;
/*
����һ:��������ż�����뿪����Ȼ��ֱ��ź����ٺϲ���һ��
������:ʹ��sort���ж�������
�������÷�����
*/
int a[1005];

bool cmp(int a,int b){
    if(a%2==b%2) return a<b;//ͬ��ͬż,ֱ�Ӵ�С��������
    else return a%2>b%2;//��ż�Բ�ͬ,������ż��ǰ��
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
