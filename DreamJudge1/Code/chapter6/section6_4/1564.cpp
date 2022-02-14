#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct node{
    int x,y;
};

char zone[105][105];
int visit[105][105];
int dir[8][2]={0,-1,0,1,-1,0,1,0,-1,-1,1,-1,-1,1,1,1};
int m,n;

int bfs(){
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(zone[i][j]=='@'&&visit[i][j]==0){//从该点开始找连通块
                ans++;
                queue<node> q;
                q.push(node{i,j});
                visit[i][j]=1;
                while(!q.empty()){
                    node now=q.front();
                    q.pop();
                    int nx=now.x,ny=now.y;
                    for(int k=0;k<8;k++){
                        int tox=nx+dir[k][0];
                        int toy=ny+dir[k][1];
                        if(zone[tox][toy]=='@'&&visit[tox][toy]==0){
                            visit[tox][toy]=1;
                            q.push(node{tox,toy});
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m==0) break;
        memset(zone,0,sizeof(zone));
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=m;i++)
            scanf("%s",zone[i]+1);
        int ans=bfs();
        printf("%d\n",ans);
    }
    return 0;
}
