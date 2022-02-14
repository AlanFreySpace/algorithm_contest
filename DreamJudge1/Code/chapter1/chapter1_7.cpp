#include <stdio.h>
#include <queue>
using namespace std;

//优先级队列的使用,默认是大顶堆
int main(){
    priority_queue<int> q;//定义优先级队列
    q.push(1);//入队
    q.push(2);
    q.push(3);
    while(!q.empty()){//判断队列不为空
        printf("%d ",q.top());//取队首元素(堆顶)
        q.pop();//堆顶出队
    }//由于是大顶堆，因此输出为:3 2 1
    return 0;
}
