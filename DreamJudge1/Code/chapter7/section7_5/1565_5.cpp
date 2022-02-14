#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
//基于链式前向星的spfa
int n,m,u,v,w,num;
int head[105],to[20005],Next[20005],weight[20005],d[105],flag[105];

void add(int x,int y,int z){
    to[++num]=y;
    weight[num]=z;
    Next[num]=head[x];
    head[x]=num;
}

void spfa(){
    queue<int> q;
    d[1]=0;
    q.push(1);
    flag[1]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        flag[x]=0;
        int index=head[x];
        while(index){
            int y=to[index];
            if(d[y]>d[x]+weight[index]){
                d[y]=d[x]+weight[index];
                if(!flag[y]){
                    q.push(y);
                    flag[y]=1;
                }
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
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        spfa();
        printf("%d\n",d[n]);
    }
    return 0;
}
