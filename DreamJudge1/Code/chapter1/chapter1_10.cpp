#include <stdio.h>
#include <iostream>
using namespace std;
//ע�⣬��CTRL+Z��־ѭ������
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)//C����ѭ������
        printf("%d\n",a+b);

    while(cin>>a>>b)//C++ѭ������
        cout<<a+b<<" C++"<<endl;
    return 0;
}
