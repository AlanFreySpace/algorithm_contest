#include <bits/stdc++.h>
using namespace std;

/*
输入一个地图:
####
#.##
##@#
####
的两种方法
*/

char c[10][10];
int main(){
    //方法一:注意j要到5，因为回车也算一个char字符
    for(int i=1;i<=4;i++){
        for(int j=1;j<=5;j++) scanf("%c",&c[i][j]);
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=5;j++) printf("%c",c[i][j]);
    }
    //方法二:此时将c[i]视作字符串,c[i]+1指明字符串的长度,这是因为字符串的末尾有
    //结束符'\0',此时回车被视为'\0'，输出时会体现为空格而不是方法一的回车
    for(int i=1;i<=4;i++) scanf("%s",c[i]+1);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=5;j++) printf("%c",c[i][j]);
        printf("\n");//因此要手动加回车
    }
    return 0;
}
