#include <stdio.h>
#include <algorithm>
using namespace std;

int a[10];

bool cmp(int a,int b){
    if(a%2==1&&b%2==1) return a>b;//奇数从大到小
    if(a%2==0&&b%2==0) return a<b;//偶数从小到大
    return a%2>b%2;//奇数在前
}

int main(){
    while(scanf("%d%d%d%d%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],
          &a[4],&a[5],&a[6],&a[7],&a[8],&a[9])!=EOF){
        sort(a,a+10,cmp);
        for(int i=0;i<10;i++) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
