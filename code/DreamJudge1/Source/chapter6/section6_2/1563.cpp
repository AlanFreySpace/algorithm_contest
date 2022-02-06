#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

char zone[105][105];
char visit[105][105];
int len[105][105];
int mo[8]={0,-1,0,1,-1,0,1,0};//代表上下左右四个方向

int main(){
    int h,w;
    while(scanf("%d%d",&h,&w)!=EOF){
        //构建迷宫
        if(h+w==0) break;
        int flag=0;
        memset(visit,0,sizeof(visit));
        memset(len,0,sizeof(len));
        queue<int> x;
        queue<int> y;
        for(int i=0;i<=w+1;i++) zone[0][i]='#';
        for(int i=0;i<=w+1;i++) zone[h+1][i]='#';
        getchar();//注意scanf会把回车当成字符,因此应getchar()消除影响
        for(int i=1;i<=h;i++){
            zone[i][0]='#';
            for(int j=1;j<=w;j++){
                scanf("%c",&zone[i][j]);
                if(zone[i][j]=='S'){
                    x.push(i);
                    y.push(j);
                    visit[i][j]=1;
                }
            }
            getchar();
            zone[i][w+1]='#';
        }

        int nowx,nowy;
        while(!x.empty()){//广度优先搜索
            nowx=x.front();
            nowy=y.front();
            x.pop();
            y.pop();
            int mox,moy;
            for(int i=0;i<4;i++){
                mox=mo[2*i];
                moy=mo[2*i+1];
                if(zone[nowx+mox][nowy+moy]!='#'&&visit[nowx+mox][nowy+moy]==0){
                    visit[nowx+mox][nowy+moy]=1;
                    len[nowx+mox][nowy+moy]=len[nowx][nowy]+1;
                    if(zone[nowx+mox][nowy+moy]=='E'){
                        flag=1;
                        break;
                    }
                    else if(zone[nowx+mox][nowy+moy]=='*'){
                        x.push(nowx+mox);
                        y.push(nowy+moy);
                    }
                }
            }
            if(flag) break;
        }
        if(flag) printf("%d\n",len[nowx][nowy]+1);
        else printf("-1\n");
    }
    return 0;
}
