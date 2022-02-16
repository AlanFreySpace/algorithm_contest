#include <stdio.h>
#include <algorithm>
#include <functional>//注意greater在这个头文件中
using namespace std;

int a[30],d[30],k;

void lengthOfLDS(){//最长递减子序列
    int len=1;
    d[1]=a[0];
    for(int i=1;i<k;i++){
        if(d[len]>=a[i]) d[++len]=a[i];
        else{//求d中第一个小于a[i]的数字的秩
            int index=upper_bound(d+1,d+len+1,a[i],greater<int>())-d;
            d[index]=a[i];
        }
    }
    printf("%d\n",len);
}

int main(){
    while(scanf("%d",&k)!=EOF){
        for(int i=0;i<k;i++) scanf("%d",&a[i]);
        lengthOfLDS();
    }
    return 0;
}
