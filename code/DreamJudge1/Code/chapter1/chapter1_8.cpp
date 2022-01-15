#include <stdio.h>
#include <vector>
using namespace std;
//向量模板的使用
int main(){
    vector<int> v; //定义一空向量
    for(int i=1;i<=10;i++) v.push_back(i*i); //依次向向量尾部添加元素
    for(int i=0;i<v.size();i++) printf("%d ",v[i]); //访问向量中元素
    return 0;
}
