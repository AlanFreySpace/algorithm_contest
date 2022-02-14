#include <stdio.h>
#include <string.h>
using namespace std;
//本题有难度,应利用好边权的性质
const int MOD=100000;
const int INF=0x3f3f3f3f;

int n,m,a,b;
int matrix[105][105],s[105],flag[105],dist[105];

int Get(int x){
    int r=s[x];
    while(r!=s[r]) r=s[r];
    int i=x,j;
    while(i!=r){
        j=s[i];
        s[i]=r;
        i=j;
    }
    return r;
}

void kruskal(){
    int len=1;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        int u=Get(a+1),v=Get(b+1);
        if(u==v){
            len=(2*len)%MOD;
            continue;
        }
        matrix[a+1][b+1]=matrix[b+1][a+1]=len;
        s[u]=v;
        len=(2*len)%MOD;
    }
}

void dijkstra(){
    dist[1]=0;
    for(int i=1;i<n;i++){
        int x=0;
        for(int j=1;j<=n;j++)
            if(!flag[j]&&dist[x]>dist[j]) x=j;
        flag[x]=1;
        for(int j=1;j<=n;j++)
            if(!flag[j]&&dist[j]>dist[x]+matrix[x][j])
                dist[j]=(dist[x]+matrix[x][j])%MOD;
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(matrix,0x3f,sizeof(matrix));
        memset(flag,0,sizeof(flag));
        memset(dist,0x3f,sizeof(dist));
        for(int i=1;i<=n;i++) s[i]=i;
        kruskal();
        dijkstra();
        for(int i=2;i<=n;i++){
            if(dist[i]!=INF) printf("%d\n",dist[i]);
            else printf("-1\n");
        }
    }
    return 0;
}
