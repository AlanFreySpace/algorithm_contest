#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct node{
    int x,y,time;
};

int n,m,t;
int sum;//��������ɢ��������
char zone[35][35];
node b;
int dir[4][2]={0,-1,0,1,-1,0,1,0};

int bfs(){
    queue<node> q;
    b.time=0;
    zone[b.x][b.y]='#';
    int num=1;
    q.push(b);
    while(!q.empty()){
        node now=q.front();
        q.pop();
        int nx=now.x,ny=now.y,nt=now.time,tox,toy,tot;
        if(nt>=t) return 1;//�����涨ʱ��
        for(int i=0;i<4;i++){
            tox=nx+dir[i][0];
            toy=ny+dir[i][1];
            tot=nt+1;
            if(zone[tox][toy]=='.'){
                zone[tox][toy]='#';
                q.push(node{tox,toy,tot});
                num++;
                if(num==sum){//������������
                    if(tot<t) return 0;//���Ǹպó���
                    else if(tot==t) return 1;//�պó���
                }
            }
        }
    }
    return 1;//������ǽ��ס,�ڹ涨ʱ�����޷�������ɢ
}

int main(){
    while(scanf("%d%d%d",&n,&m,&t)!=EOF){
        memset(zone,0,sizeof(zone));
        sum=0;
        for(int i=1;i<=n;i++){
            scanf("%s",zone[i]+1);
            for(int j=1;j<=m;j++){
                if(zone[i][j]=='*'){
                    b.x=i;
                    b.y=j;
                    sum++;
                }
                else if(zone[i][j]=='.') sum++;
            }
        }

        int flag=bfs();
        if(flag==0) printf("No\n\n");
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)
                    printf("%c",zone[i][j]);
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
