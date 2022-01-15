#include <stdio.h>
using namespace std;

/*
考察数组的嵌套使用。
输入 N（N<=100）个整数，每个数的范围> 0 并且 <= 100，请将每个不同的数输出并且输出它
对应的个数。要求按值出现的次数从小到大排序，如果多个值有相同的个数，只用输出值最大的那个。
样例输入 8                      样例输出 4 1
         3 2 2 1 1 4 5 5                 5 2
*/

int f[101];//f[i]是数字i出现的次数
int p[101];//p[i]是出现了i次的数中最大的那个

int main(){
    int N;
    scanf("%d",&N);
    int num;
    for(int i=0;i<N;i++){
       scanf("%d",&num);
       f[num]++;
    }
    for(int i=1;i<=100;i++) p[f[i]]=i;
    for(int i=1;i<=100;i++){
        if(p[i]>0) printf("%d %d\n",p[i],i);
    }
    return 0;
}
