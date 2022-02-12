#include <stdio.h>
#include <string.h>
using namespace std;
//bellman-fordÀ„∑®
struct edge{
    int u,v,w;
}e[20005];

int n,m,num,x,y,z;
int d[105];

void bellman(){
    d[1]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<num;j++){
            x=e[j].u,y=e[j].v,z=e[j].w;
            if(d[y]>d[x]+z) d[y]=d[x]+z;
        }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        memset(d,0x3f,sizeof(d));
        num=0;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&x,&y,&z);
            e[num].u=x,e[num].v=y,e[num++].w=z;
            e[num].v=x,e[num].u=y,e[num++].w=z;
        }
        bellman();
        printf("%d\n",d[n]);
    }
    return 0;
}
