#include <stdio.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

//��x��y����С������LCM
int main(){
    int x,y,lcm;
    while(scanf("%d%d",&x,&y)!=EOF){
        lcm=x*y/gcd(x,y);
        printf("%d\n",lcm);
    }
    return 0;
}
