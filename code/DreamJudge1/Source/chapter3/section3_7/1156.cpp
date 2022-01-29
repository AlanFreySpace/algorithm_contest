#include <stdio.h>
#include <math.h>
using namespace std;

//参考算法竞赛进阶指南137页
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        for(int i=2;i<=sqrt(n);i++){//注意n是不断变化的
            if(n%i==0)
                while(n%i==0){
                    ans++;
                    n/=i;
                }
        }
        if(n>1) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
