#include <stdio.h>
#include <string.h>
using namespace std;

//Dijkstra算法,邻接矩阵存储,未使用二叉堆
int n,m,u,v,w;
int matrix[105][105],d[105],flag[105];

void dijkstra(){
    d[1]=0;
    for(int i=1;i<n;i++){
        int x=0;
        for(int j=1;j<=n;j++)
            if(!flag[j]&&d[j]<d[x]) x=j;
        flag[x]=1;
        for(int j=1;j<=n;j++)
            if(d[j]>d[x]+matrix[x][j])
                d[j]=d[x]+matrix[x][j];
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        memset(matrix,0x3f,sizeof(matrix));
        memset(d,0x3f,sizeof(d));
        memset(flag,0,sizeof(flag));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(w<matrix[u][v])
                matrix[u][v]=matrix[v][u]=w;
        }
        dijkstra();
        printf("%d\n",d[n]);
    }
    return 0;
}
