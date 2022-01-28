#include <stdio.h>
using namespace std;

//求x和y的最大公约数
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF){
        int m=gcd(x,y);
        printf("%d\n",m);
    }
    return 0;
}
