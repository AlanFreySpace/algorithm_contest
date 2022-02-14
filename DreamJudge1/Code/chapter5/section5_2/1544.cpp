#include <stdio.h>
#include <queue>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        //注意如何定义小顶堆
        priority_queue<int,vector<int>,greater<int> > q;
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
            int num=num1+num2;
            ans+=num;
            q.push(num);
        }
        printf("%d\n",ans);
    }
    return 0;
}
