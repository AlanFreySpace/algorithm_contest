#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

/*
Dijkstra算法,链式前向星存储,使用二叉堆,注意链式前向星存储将无向边视为两个
有向边,因此to Next weight数组至少开到20000多一些
*/
int n,m,u,v,w,num;
int head[105],to[20050],Next[20050],weight[20050],d[105],flag[105];

void add(int x,int y,int z){//添加由x指向y的权重为z的边
    to[++num]=y;
    weight[num]=z;
    Next[num]=head[x];
    head[x]=num;
}

void dijkstra(){
    d[1]=0;
    priority_queue<pair<int,int> > q;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int x=q.top().second;
        q.pop();
        if(flag[x]) continue;
        flag[x]=1;
        int index=head[x];
        while(index){
            int y=to[index];
            if(d[y]>d[x]+weight[index]){
                d[y]=d[x]+weight[index];
                q.push(make_pair(-d[y],y));
            }
            index=Next[index];
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        num=1;
        memset(head,0,sizeof(head));
        memset(Next,0,sizeof(Next));
        memset(d,0x3f,sizeof(d));
        memset(flag,0,sizeof(flag));
        for(int i=0;i<m;i++){//构建链式前向星方式存储的图
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }

        dijkstra();
        printf("%d\n",d[n]);
    }
    return 0;
}
