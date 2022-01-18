#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

/*
注意应将字符串a和b反转过来,这样做是为了利用乘积的高位
必不为0的特性,便于打印字符串
res的低位存数字的低位,高位存数字的高位
*/
int main(){
    int n;
    string a,b;
    int res[210]={0};//将res所有元素初始化为0
    cin>>n>>a>>b;
    reverse(a.begin(),a.end());//反转字符串
    reverse(b.begin(),b.end());
    for(int i=0;i<n;i++){//计算
        for(int j=0;j<n;j++)
            res[i+j]+=(a[i]-'0')*(b[j]-'0');
    }
    for(int i=0;i<2*n-1;i++){//进位
        if(res[i]>9){
            res[i+1]+=(res[i]/10);
            res[i]%=10;
        }
    }
    int flag=209;
    while(true){
        if(res[flag]!=0) break;
        flag--;
    }
    //printf("%d",flag);
    for(int i=flag;i>=0;i--) printf("%d",res[i]);
    return 0;
}
