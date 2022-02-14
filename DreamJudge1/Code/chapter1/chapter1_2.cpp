#include <stdio.h>
using namespace std;

/*
输入 N（N<=100）个整数，每个数的范围> 0 并且 <= 100，请将每个不同的数从小到大输出并且输出它对应的个数。
样例输入 8                          样例输出 1 2
         3 2 2 1 1 4 5 5                     2 2
                                             3 1
                                             4 1
                                             5 2
*/

int f[101];//注意int数组初始化就是所有元素均为0
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
