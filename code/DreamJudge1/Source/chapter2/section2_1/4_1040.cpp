#include <bits/stdc++.h>
using namespace std;

int main(){
    double a,res=0,tmp=0;//tmp是当前提成计算部分
    scanf("%lf",&a);
    if(a>1000000){
        tmp=a-1000000;
        res+=tmp*0.01;
        a-=tmp;
    }
    if(a>600000){
        tmp=a-600000;
        res+=tmp*0.015;
        a-=tmp;
    }
    if(a>400000){
        tmp=a-400000;
        res+=tmp*0.03;
        a-=tmp;
    }
    if(a>200000){
        tmp=a-200000;
        res+=tmp*0.05;
        a-=tmp;
    }
    if(a>100000){
        tmp=a-100000;
        res+=tmp*0.075;
        a-=tmp;
    }
    res+=a*0.1;
    printf("%g",res);
    return 0;
}
