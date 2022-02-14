#include <stdio.h>
#include <string.h>
using namespace std;

/*
dijkstra算法呈现一种树形扩散的构建最短路的方式
因此在使用dijkstra时，因为城市1属于一号势力，城市2属于二号势力，
所以在更新d[]时判断一下中间点属于哪一方势力就可对路径进行限制。
u为中间点，v为待更新点，若u属于一号势力，则v无限制，
若u属于二号势力，则v只能属于二号势力
*/

const int INF=0x3f3f3f3f;
int n,m,u,v,w;
int matrix[605][605],d[605],city[605],visit[605];

void dijkstra(){
    d[1]=0;
    for(int i=1;i<n;i++){
        int x=0;
        for(int j=1;j<=n;j++)
            if(!visit[j]&&d[j]<d[x]) x=j;
        visit[x]=1;
        for(int j=1;j<=n;j++){
            if(!visit[j]&&!(city[x]==2&&city[j]==1)
               &&d[j]>d[x]+matrix[x][j]){
                d[j]=d[x]+matrix[x][j];
            }
        }
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        scanf("%d",&m);
        memset(matrix,0x3f,sizeof(matrix));
        memset(d,0x3f,sizeof(d));
        memset(visit,0,sizeof(visit));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(matrix[u][v]>w)
                matrix[u][v]=matrix[v][u]=w;
        }
        for(int i=1;i<=n;i++) scanf("%d",&city[i]);
        dijkstra();
        if(d[2]!=INF) printf("%d\n",d[2]);
        else printf("-1\n");
    }
    return 0;
}
