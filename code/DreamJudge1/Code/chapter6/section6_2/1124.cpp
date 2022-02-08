#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct node{
    int x,y,time;
};

char zone[105][105];
node gb,sb;
int c,n,m,t;
int dir[4][2]={0,-1,0,1,-1,0,1,0};

int bfs(){
    queue<node> gq,sq;
    gq.push(gb);
    sq.push(sb);
    int snum=1;
    for(int i=0;i<t;i++){//����t����ɢ
        int diffuse=0;//���������Ƿ�����ɢ
        while(!gq.empty()){//������i+1����ɢ�Ĺ���
            node ng=gq.front();
            if(ng.time!=i) break;
            gq.pop();
            int ngx=ng.x,ngy=ng.y,ngt=ng.time;
            for(int j=0;j<4;j++){
                int tox=ngx+dir[j][0];
                int toy=ngy+dir[j][1];
                if(zone[tox][toy]=='S'){//�������ǵ���ȫλ��
                    diffuse=1;
                    zone[tox][toy]='G';
                    snum--;
                    if(snum==0) return 0;//�������а�ȫλ��
                    gq.push(node{tox,toy,ngt+1});
                }
                else if(zone[tox][toy]=='.'){//�������ǵ�����λ��
                    diffuse=1;
                    zone[tox][toy]='G';
                    gq.push(node{tox,toy,ngt+1});
                }
            }
        }
        if(diffuse==0) return 1;//����δ��ɢ,ֱ�ӷ���
        while(!sq.empty()){//��ȫλ����i+1����ɢ�Ĺ���
            node ns=sq.front();
            if(ns.time!=i) break;
            sq.pop();
            int nsx=ns.x,nsy=ns.y,nst=ns.time;
            if(zone[nsx][nsy]=='S'){
                for(int j=0;j<4;j++){
                    int tox=nsx+dir[j][0];
                    int toy=nsy+dir[j][1];
                    if(zone[tox][toy]=='.'){
                        zone[tox][toy]='S';
                        snum++;
                        sq.push(node{tox,toy,nst+1});
                    }
                }
            }
        }
        diffuse=0;
    }
    return 1;
}

int main(){
    scanf("%d",&c);
    for(int i=0;i<c;i++){
        scanf("%d%d%d",&n,&m,&t);
        memset(zone,0,sizeof(zone));
        for(int j=1;j<=n;j++){
            scanf("%s",zone[j]+1);
            for(int k=1;k<=m;k++){
                if(zone[j][k]=='G'){
                    gb.x=j;
                    gb.y=k;
                    gb.time=0;
                }
                else if(zone[j][k]=='S'){
                    sb.x=j;
                    sb.y=k;
                    sb.time=0;
                }
            }
        }

        int flag=bfs();
        if(flag==0) printf("No\n");
        else{
            for(int j=1;j<=n;j++){
                for(int k=1;k<=m;k++)
                    printf("%c",zone[j][k]);
                printf("\n");
            }
        }
    }
    return 0;
}
