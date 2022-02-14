#include <algorithm>
#include <stdio.h>
using namespace std;

/*
C++ STL:
sort()函数:
依次传入三个参数,即:
要排序区间的起点，要排序区间的终点+1，比较函数。
比较函数可以不填，则默认为从小到大排序。
比较函数的使用参考:
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
