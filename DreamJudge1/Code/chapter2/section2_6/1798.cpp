#include <stdio.h>
#include <algorithm>
using namespace std;

/*
本题关键:注意如何读取带逗号的数据
*/
int main(){
    int a[1000];
    int i=0,tmp;
    while(scanf("%d",&tmp)!=EOF){//读取int,注意这里不要写成scanf("%d",&a[i++])!=EOF
         a[i]=tmp;   //这是因为不同编译器对该语句处理不同,有的编译器读到EOF时会对i加1
         i++;        //有的不会
         if(getchar()=='\n') break;//读取\n即换行符或逗号
    }
    sort(a,a+i);
    for(int j=0;j<i;j++){
        printf("%d ",a[j]);
        if(j%4==3) printf("\n");
    }
    return 0;
}
