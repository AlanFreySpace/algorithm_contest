#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Data{//为了使用scanf进行字符串输入输出,需要定义结构体
    char data[1005];
}d[105];

bool cmp(Data a,Data b){
    if(strlen(a.data)!=strlen(b.data)) return strlen(a.data)<strlen(b.data);
    return strcmp(a.data,b.data)<0;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%s",&d[i].data);
        sort(d,d+n,cmp);
        for(int i=0;i<n;i++) printf("%s\n",d[i].data);
    }
    return 0;
}
