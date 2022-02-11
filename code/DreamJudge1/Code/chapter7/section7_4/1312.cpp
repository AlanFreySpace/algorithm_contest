#include <stdio.h>
#include <algorithm>
using namespace std;

//应用kruskal算法解决最小生成树问题 罗勇军256
struct edge{
    int u,v,w;
}e[105];

int n,m;
int s[105];

bool cmp(edge e1,edge e2){
    return e1.w<e2.w;
}

int Get(int x){//并查集用于判断是否有环
    int r=s[x];
    while(r!=s[r]) r=s[r];
    int i=x,j;
    while(i!=r){//路径压缩
        j=s[i];
        s[i]=r;
        i=j;
    }
    return r;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0) break;
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sort(e,e+n,cmp);
        for(int i=1;i<=m;i++) s[i]=i;
        int num=m,ans=0;//注意num应从m开始,用于判断图是否连通
        for(int i=0;i<n;i++){
            int a=Get(e[i].u),b=Get(e[i].v);
            if(a==b) continue;
            s[a]=b;
            num--;
            ans+=e[i].w;
            if(num==1) break;
        }
        if(num!=1) printf("?\n");
        else printf("%d\n",ans);
    }
    return 0;
}
