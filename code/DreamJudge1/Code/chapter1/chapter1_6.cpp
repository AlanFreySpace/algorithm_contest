#include <stdio.h>
#include <algorithm>
#include <functional>//greater包含在这个头文件中
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int a[10]={5,3,69,23,7,4,69,100,1,36};
    /*
    从小到大排序与bound结合实现二分查找，在a[0,9]中查找
    lower_bound:查找排序后第一个大于等于69的值的秩，若不存在返回10
    upper_bound:查找排序后第一个大于69的值的秩，若不存在返回10
    */
    sort(a,a+10);
    printf("%d ",lower_bound(a,a+10,69)-a);//输出7
    printf("%d ",upper_bound(a,a+10,69)-a);//输出9
    /*
    从大到小排序与bound和greater结合实现二分查找，在a[0,9]中查找
    lower_bound:查找排序后第一个小于等于69的值的秩，若不存在返回10
    upper_bound:查找排序后第一个小于69的值的秩，若不存在返回10
    */
    sort(a,a+10,cmp);
    printf("%d ",lower_bound(a,a+10,69,greater<int>())-a);//输出1
    printf("%d ",upper_bound(a,a+10,69,greater<int>())-a);//输出3
    return 0;
}
