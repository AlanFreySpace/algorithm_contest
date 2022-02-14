#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,x,y,w,c;
int matrix[105][105],flag[105],d[105];
//题干描述的是稠密图,因此用prim算法
void prim(){
    d[1]=0;
    for(int i=1;i<n;i++){
        int x=0;
        for(int j=1;j<=n;j++)
            if(!flag[j]&&d[j]<d[x]) x=j;
        flag[x]=1;
        for(int j=1;j<=n;j++)
            if(!flag[j]) d[j]=min(d[j],matrix[x][j]);
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        memset(matrix,0x3f,sizeof(matrix));
        memset(flag,0,sizeof(flag));
        memset(d,0x3f,sizeof(d));
        int num=n*(n-1)/2;
        for(int i=0;i<num;i++){//构建邻接矩阵
            scanf("%d%d%d%d",&x,&y,&w,&c);
            if(c==1) w=0;
            matrix[x][y]=matrix[y][x]=w;
        }
        prim();
        int ans=0;
        for(int i=1;i<=n;i++) ans+=d[i];
        printf("%d\n",ans);
    }
    return 0;
}
