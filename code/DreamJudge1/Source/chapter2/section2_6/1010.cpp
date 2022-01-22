#include <stdio.h>
#include <algorithm>
using namespace std;
/*
方法一:将奇数和偶数分离开来，然后分别排好序，再合并在一起
方法二:使用sort进行二级排序
本代码用方法二
*/
int a[1005];

bool cmp(int a,int b){
    if(a%2==b%2) return a<b;//同奇同偶,直接从小到大排序
    else return a%2>b%2;//奇偶性不同,奇数在偶数前面
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
