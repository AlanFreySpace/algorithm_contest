#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int mpt[105][105];
int dp[105][105];
int dir[4][2]={0,-1,0,1,-1,0,1,0};

int dfs(int x,int y){
    if(dp[x][y]) return dp[x][y];
    int maxd=1;//由该点开始可以深度优先搜索的最大深度
    for(int i=0;i<4;i++){
        int tox=x+dir[i][0],toy=y+dir[i][1];
        if(mpt[x][y]>mpt[tox][toy])
            maxd=max(maxd,dfs(tox,toy)+1);
    }
    dp[x][y]=maxd;//注意不要忘记忆化
    return maxd;
}

int main(){
    int r,c;
    while(scanf("%d%d",&r,&c)!=EOF){
        memset(mpt,0x3f,sizeof(mpt));
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++) scanf("%d",&mpt[i][j]);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++) ans=max(ans,dfs(i,j));
        printf("%d\n",ans);
    }
    return 0;
}
