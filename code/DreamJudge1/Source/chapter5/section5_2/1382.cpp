#include <stdio.h>
#include <queue>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        priority_queue<int,vector<int>,greater<int> > q;//小顶堆
        int tmp,ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            q.push(tmp);
        }

        for(int i=0;i<n-1;i++){
            int num1=q.top();
            q.pop();
            int num2=q.top();
            q.pop();
            ans+=(num1+num2);
            q.push(num1+num2);
        }//注意这种累加计算的方法
        printf("%d\n",ans);
    }
}
