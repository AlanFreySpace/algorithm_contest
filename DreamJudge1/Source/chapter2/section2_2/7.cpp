#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main(){
    /*
    字符串转浮点数:
    c_str()函数将string转换为字符数组,而atof()将字符数组转换为浮点数,
    注意atof的返回值是double类型
    */
    string a="31.75";
    float x1=atof(a.c_str());
    double x2=atof(a.c_str());
    printf("%g %g \n",x1,x2);

    /*
    浮点数转字符串
    */
    float a1=31.25;
    double a2=33.96;
    stringstream ss;
    ss<<a1;
    string ans1=ss.str();
    ss.str("");//清空ss的缓冲区
    ss<<a2;
    string ans2=ss.str();
    cout<<ans1<<" "<<ans2<<endl;

    //字符串转整形
    string t1="139";
    int ans3=atoi(t1.c_str());

    /*
    整形转字符串:itoa()函数有3个参数：第一个参数是要转换的数字，
    第二个参数是要写入转换结果的目标字符串，
    第三个参数是转换数字时所用的基数。
    */
    int t2=567;
    char ans4[105];
    itoa(t2,ans4,10);
    printf("%d %s\n",ans3,ans4);
    return 0;
}
