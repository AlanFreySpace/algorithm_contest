#include <stdio.h>
#include <vector>
using namespace std;

//向量解法
int main(){
    int n,s,m;
    int ans[105];//保存猴子退出顺序
    vector<int> v;
    while(scanf("%d%d%d",&n,&s,&m)!=EOF){
       if(n==0&&s==0&&m==0) break;
       for(int i=0;i<n;i++) v.push_back(i+1);
       int cur=s-1;//cur表示开始报数的猴子的下标
       for(int i=0;i<n;i++){
           int del=(cur+m-1)%v.size();//要退出的猴子下标
           ans[i]=v[del];
           v.erase(v.begin()+del);
           //注意这里极爱出错，要认真
           if(i<n-1) cur=del%v.size();//下一开始报数的猴子的下标
       }
       for(int i=0;i<n-1;i++) printf("%d,",ans[i]);
       printf("%d",ans[n-1]);
       printf("\n");
    }
    return 0;
}
