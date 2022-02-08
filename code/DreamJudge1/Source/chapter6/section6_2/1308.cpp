#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

/*
样例:
8 7
...W...
###.###
###.###
#######
#######
w#####f
.#####.
..####.
*/

struct node{
    int x,y;
};

int n,m;
char zone[105][105];//迷宫
int visit[105][105][3];//三人到各点需要去掉最少的障碍物数量
node b[3];//三人的起点
int dir[4][2]={0,-1,0,1,-1,0,1,0};//上下左右四个方向

void bfs(int index){
    queue<node> q;
    int bx=b[index].x,by=b[index].y;
    visit[bx][by][index]=0;
    q.push(b[index]);
    while(!q.empty()){
        node now=q.front();
        q.pop();
        bx=now.x;
        by=now.y;
        for(int i=0;i<4;i++){
            int tox=bx+dir[i][0];
            int toy=by+dir[i][1];
            if(tox<1||tox>n||toy<1||toy>m) continue;
            int tmp=visit[bx][by][index];
            if(zone[tox][toy]=='#') tmp++;
            if(tmp<visit[tox][toy][index]){
                visit[tox][toy][index]=tmp;
                q.push(node{tox,toy});
            }
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(zone,0,sizeof(zone));
        memset(visit,0x3f,sizeof(visit));
        for(int i=1;i<=n;i++){//输入迷宫,并得到三人的起点
            scanf("%s",zone[i]+1);
            for(int j=1;j<=m;j++){
                if(zone[i][j]=='w'){
                    b[0].x=i;
                    b[0].y=j;
                }
                else if(zone[i][j]=='W'){
                    b[1].x=i;
                    b[1].y=j;
                }
                else if(zone[i][j]=='f'){
                    b[2].x=i;
                    b[2].y=j;
                }
            }
        }

        bfs(0);
        bfs(1);
        bfs(2);
        int ans=1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int tmp=visit[i][j][0]+visit[i][j][1]+visit[i][j][2];
                if(zone[i][j]=='#') tmp-=2;//相聚于# 则多算了2个
                if(tmp<ans) ans=tmp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
