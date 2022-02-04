#include <stdio.h>
using namespace std;

//注意用差分加速更新,参考算法竞赛进阶指南23页
int main(){
    int wall[200005]={0};
    int b,e;
    while(scanf("%d%d",&b,&e)){
        if(b==0&&e==0) break;
        wall[b]++;
        wall[e+1]--;
    }
    for(int i=1;i<200005;i++) wall[i]+=wall[i-1];
    while(scanf("%d%d",&b,&e)){
        if(b==0&&e==0) break;
        for(int i=b;i<=e;i++) printf("%d\n",wall[i]);
    }
    return 0;
}
