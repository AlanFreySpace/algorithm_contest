#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int depth=-1;//depth为1表明该点没有处理过
    vector<int> relate;
}node[10000];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int tmp1,tmp2;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&tmp1,&tmp2);
        node[tmp1].relate.push_back(tmp2);
        node[tmp2].relate.push_back(tmp1);
    }

    queue<int> q;
    q.push(m);
    node[m].depth=1;
    int ans;
    while(!q.empty()){//从根节点向下层次遍历
        int now=q.front(),d=node[now].depth,cur;
        q.pop();
        while(!node[now].relate.empty()){
            cur=node[now].relate[node[now].relate.size()-1];
            node[now].relate.pop_back();
            if(node[cur].depth==-1){
                node[cur].depth=d+1;
                q.push(cur);
            }
        }
        ans=d;
    }
    printf("%d",ans-1);
    return 0;
}
