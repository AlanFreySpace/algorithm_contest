#include <stdio.h>
#include <iostream>
using namespace std;
//注意，用CTRL+Z标志循环结束
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)//C语言循环读入
        printf("%d\n",a+b);

    while(cin>>a>>b)//C++循环读入
        cout<<a+b<<" C++"<<endl;
    return 0;
}
