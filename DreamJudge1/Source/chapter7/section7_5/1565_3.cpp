#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

/*
Dijkstra�㷨,��ʽǰ���Ǵ洢,ʹ�ö����,ע����ʽǰ���Ǵ洢���������Ϊ����
�����,���to Next weight�������ٿ���20000��һЩ
*/
int n,m,u,v,w,num;
int head[105],to[20050],Next[20050],weight[20050],d[105],flag[105];

void add(int x,int y,int z){//�����xָ��y��Ȩ��Ϊz�ı�
    to[++num]=y;
    weight[num]=z;
    Next[num]=head[x];
    head[x]=num;
}

void dijkstra(){
    d[1]=0;
    priority_queue<pair<int,int> > q;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int x=q.top().second;
        q.pop();
        if(flag[x]) continue;
        flag[x]=1;
        int index=head[x];
        while(index){
            int y=to[index];
            if(d[y]>d[x]+weight[index]){
                d[y]=d[x]+weight[index];
                q.push(make_pair(-d[y],y));
            }
            index=Next[index];
        }
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        num=1;
        memset(head,0,sizeof(head));
        memset(Next,0,sizeof(Next));
        memset(d,0x3f,sizeof(d));
        memset(flag,0,sizeof(flag));
        for(int i=0;i<m;i++){//������ʽǰ���Ƿ�ʽ�洢��ͼ
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }

        dijkstra();
        printf("%d\n",d[n]);
    }
    return 0;
}
