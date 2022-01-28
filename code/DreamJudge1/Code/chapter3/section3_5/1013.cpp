#include <stdio.h>
#include <math.h>
using namespace std;

//注意sqrt返回的是double类型
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==1) n++;
        for(int i=n;;i++){//判断i是否是素数
            int flag=0;
            for(int j=2;j<=sqrt(i);j++){//对i可能的因子逐一试探
                if(i%j==0){//i是合数
                    flag=1;
                    break;
                }
            }
            if(flag==0){//i是素数
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
