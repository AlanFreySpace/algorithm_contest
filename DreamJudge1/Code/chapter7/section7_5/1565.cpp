#include <stdio.h>
using namespace std;

const int INF=1e9;
int n,m,u,v,w;
int matrix[105][105];
//floyd-warshall法,时间复杂度高
void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            if(matrix[i][k]!=INF)
                for(int j=1;j<=n;j++)
                    if(matrix[i][j]>matrix[i][k]+matrix[k][j])
                        matrix[i][j]=matrix[i][k]+matrix[k][j];
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++) matrix[i][j]=INF;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(w<matrix[u][v])
                matrix[u][v]=matrix[v][u]=w;
        }
        floyd();
        printf("%d\n",matrix[1][n]);
    }
    return 0;
}
