#include <stdio.h>
#include <string.h>
using namespace std;

int v[1005];//v[i]是i的最小质因子
int prime[1005];//记录素数

/*
利用欧拉筛法(算法竞赛进阶指南P136)
得到[2,n]之间的素数,返回素数的个数
*/
int getprime(int n){
    memset(v,0,sizeof(v));
    int m=0;//记录素数的个数
    for(int i=2;i<=n;i++){
        if(v[i]==0){//发现素数
            v[i]=i;
            prime[m++]=i;
        }
        for(int j=0;j<m&&prime[j]*i<=n;j++)//筛合数
            v[prime[j]*i]=prime[j];
    }
    return m;
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a>b){
            int tmp=a;
            a=b;
            b=tmp;
        }
        int m=getprime(b);
        int num=0;
        for(int i=0;i<m;i++){
            if(prime[i]>=a&&prime[i]<=b) num++;
        }
        printf("%d\n",num);
    }
    return 0;
}
