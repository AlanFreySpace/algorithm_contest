#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int maxm=200005;
const int maxn=1005;

int n,m,a,b,d,p,s,t,num;
int head[maxn],to[maxm],Next[maxm],w[maxm],ww[maxm];
int dist[maxn],cost[maxn],flag[maxn];

void add(int a,int b,int d,int p){
    to[++num]=b;
    w[num]=d;
    ww[num]=p;
    Next[num]=head[a];
    head[a]=num;
}

void spfa(int s){
    dist[s]=cost[s]=0;
    queue<int> q;
    q.push(s);
    flag[s]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        flag[x]=0;
        int index=head[x];
        while(index){
            int y=to[index];
            if(dist[y]==dist[x]+w[index]&&cost[y]>cost[x]+ww[index]){
                cost[y]=cost[x]+ww[index];
                if(!flag[y]){
                    q.push(y);
                    flag[y]=1;
                }
            }//距离相同则选择花费最少的
            else if(dist[y]>dist[x]+w[index]){
                dist[y]=dist[x]+w[index];
                cost[y]=cost[x]+ww[index];
                if(!flag[y]){
                    q.push(y);
                    flag[y]=1;
                }
            }//选择距离短的
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
        memset(dist,0x3f,sizeof(dist));
        memset(cost,0x3f,sizeof(cost));
        memset(flag,0,sizeof(flag));
        for(int i=0;i<m;i++){
            scanf("%d%d%d%d",&a,&b,&d,&p);
            add(a,b,d,p);
            add(b,a,d,p);
        }
        scanf("%d%d",&s,&t);
        spfa(s);
        printf("%d %d\n",dist[t],cost[t]);
    }
    return 0;
}
