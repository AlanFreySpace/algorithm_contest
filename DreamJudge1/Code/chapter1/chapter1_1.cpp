#include <bits/stdc++.h>  //万能头文件，不过有的评测机不支持
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <functional>
#include <string>  //常用头文件
using namespace std;

int main(){
    int x1;
    double x2;
    char x3;
    char x4[10];//字符串最长为9，因为有结束符\0
    scanf("%d %lf %c %s",&x1,&x2,&x3,&x4);//输入int double char 字符串数组类型变量
    printf("%d\n%lf\n%c\n%s\n",x1,x2,x3,x4);//并输出

    int year,month,day;//输入解析，可解析2019-10-21这样的输入为年月日
    scanf("%d-%d-%d",&year,&month,&day);
    printf("%d %d %d\n",year,month,day);

    int hour,minute,second;//解析18:21:30这样的时间
    scanf("%d:%d:%d",&hour,&minute,&second);
    printf("%d %d %d\n",hour,minute,second);

    char s[105];//输入的字符串带空格应该用gets.因为scanf遇到空格时会自动结束
    getchar();//该getchar会读到上一个scanf的结束符而结束,一般在scanf和gets中间使用getchar用于
    //消除回车'\n'的影响，getchar()用于读入单个字符
    gets(s);//例子:how are you?
    printf("%s\n",s);

    char c1=getchar();//getchar() 读入单个字符
    putchar(c1);//putchar(char) 输出单个字符
    printf("\n");

    //输出进制转换
    int a=10;//十进制
    printf("%x\n",a);//小写十六进制输出:a
    printf("%X\n",a);//大写十六进制输出:A
    printf("%o\n",a);//八进制输出:12

    //输出增加前置0
    a=5;
    printf("%02d\n",a);//其中2代表宽度,不足的地方用0补充,输出05
    printf("%04d\n",a);//类似的含义，输出:0005

    //输出保留小数
    double a1;
    scanf("%lf",&a1);
    printf("%.2lf\n",a1);//输出保留两位小数    例子：分别输入3.6 3 5.769 分别输出
    //3.60 3.00 5.77
    printf("%g\n",a1);//若有小数输出小数，没小数输出整数 输出3.6 3 5.769

    long long x5;//int范围不够时用long long，int范围-1e9到1e9，long long范围-1e18到1e18
    scanf("%lld",&x5);
    printf("%lld\n",x5);

    //输出字符的ASCII码，注意char字符和int值可以相互转化
    printf("%d\n",'a');//输出97
    printf("%d\n",'A');//输出65

    //C++的输入输出，注意string类的输入输出只能用cin cout
    //printf尽量不要和cout同时使用，可能发生一些不可控的意外
    int x6,x7;
    cin>>x6>>x7;
    cout<<x6+x7;
    return 0;
}

