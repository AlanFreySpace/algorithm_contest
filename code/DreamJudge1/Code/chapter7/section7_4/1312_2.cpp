#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//应用prim算法解决最小生成树问题
int n,m,x,y,w;
int matrix[105][105],flag[105],d[105];
//罗勇军254+李煜东363
int prim(){
    d[1]=0;
    for(int i=1;i<=m;i++){
        int x=0;
        for(int j=1;j<=m;j++)//尝试扩充最小生成树中的顶点x
            if(!flag[j]&&d[j]<d[x]) x=j;
        if(x!=0){//扩充成功,应更新已在最小生成树中顶点与
            flag[x]=1;//剩余各顶点之间的权重最小的边
            for(int j=1;j<=m;j++)
                if(!flag[j]) d[j]=min(d[j],matrix[x][j]);
        }
        else return 0;//x==0时即扩充失败
    }
    return 1;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0) break;
        memset(matrix,0x3f,sizeof(matrix));
        memset(flag,0,sizeof(flag));
        memset(d,0x3f,sizeof(d));
        //构建邻接矩阵
        for(int i=1;i<=m;i++) matrix[i][i]=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&w);
            matrix[x][y]=min(w,matrix[x][y]);//注意多重边中应取最小的
            matrix[y][x]=matrix[x][y];
        }
        int con=prim();
        if(!con) printf("?\n");
        else{
            int ans=0;
            for(int i=1;i<=m;i++) ans+=d[i];
            printf("%d\n",ans);
        }
    }
    return 0;
}
