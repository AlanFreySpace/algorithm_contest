#include <stdio.h>
using namespace std;

#define INF 1e9

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int minNum=INF,maxNum=-INF,tmp;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            if(tmp<minNum) minNum=tmp;
            if(tmp>maxNum) maxNum=tmp;
        }
        printf("%d %d %d\n",minNum,maxNum,gcd(minNum,maxNum));
    }
    return 0;
}
