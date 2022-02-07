#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

char zone[105][105];//代表迷宫
int visit[105][105];//代表该点是否被访问过
int dir[4][2]={0,-1,0,1,-1,0,1,0};//代表上下左右四个方位

struct node{
    int x,y;//点的位置
    int step;//从S到该点的最短距离
};

int bfs(int sx,int sy){
    queue<node> q;
    visit[sx][sy]=1;
    q.push(node{sx,sy,0});
    int ans=-1;
    while(!q.empty()){
        node now=q.front();
        q.pop();
        int nx=now.x,ny=now.y;
        if(zone[nx][ny]=='E'){
            ans=now.step;
            break;
        }
        int tox,toy;
        for(int i=0;i<4;i++){
            tox=nx+dir[i][0];
            toy=ny+dir[i][1];
            if((zone[tox][toy]=='*'||zone[tox][toy]=='E')&&visit[tox][toy]==0){
                visit[tox][toy]=1;
                q.push(node{tox,toy,now.step+1});
            }
        }
    }
    return ans;
}

int main(){
    int h,w;
    while(scanf("%d%d",&h,&w)!=EOF){
        if(h==0&&w==0) break;
        memset(zone,0,sizeof(zone));
        memset(visit,0,sizeof(visit));
        int sx=0,sy=0;
        for(int i=1;i<=h;i++){
            scanf("%s",zone[i]+1);
            for(int j=1;j<=w;j++){
                if(zone[i][j]=='S'){
                    sx=i;
                    sy=j;
                }
            }
        }
        int ans=bfs(sx,sy);
        printf("%d\n",ans);
    }
    return 0;
}
