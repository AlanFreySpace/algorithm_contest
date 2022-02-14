#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

/*
注意这种写法是错误的,原因:
幂次无法代表2的幂的大小。
举例:输入
5 5
0 1
1 2
2 3
3 4
0 4
将输出错误结果:
1
3
7
16
*/
const int INF=0x3f3f3f3f;

int n,m,a,b,num;
int head[105],to[1005],w[1005],Next[1005];
int d[105],ans[105],flag[105],modd[505];

void compute(){//modd[i]代表2^i mod 100000
    modd[0]=1;
    for(int i=1;i<505;i++) modd[i]=(modd[i-1]*2)%100000;
}

void add(int x,int y,int z){
    to[++num]=y;
    w[num]=z;
    Next[num]=head[x];
    head[x]=num;
}

void spfa(){
    queue<int> q;
    d[1]=0;
    q.push(1);
    flag[1]=1;
    ans[1]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        flag[x]=0;
        int index=head[x];
        while(index){
            int y=to[index],z=w[index];
            if(d[y]>d[x]+z){//此处是错误的
                d[y]=d[x]+z;
                ans[y]=(ans[x]+modd[z])%100000;
                if(!flag[y]){
                    q.push(y);
                    flag[y]=1;
                }
            }
            index=Next[index];
        }
    }
}

int main(){
    compute();
    while(scanf("%d%d",&n,&m)!=EOF){
        num=1;
        memset(head,0,sizeof(head));
        memset(Next,0,sizeof(Next));
        memset(d,0x3f,sizeof(d));
        memset(flag,0,sizeof(flag));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            add(a+1,b+1,i);
            add(b+1,a+1,i);//使得城市编号从1开始
        }
        spfa();
        for(int i=2;i<=n;i++){
            if(d[i]==INF) printf("-1\n");
            else printf("%d\n",ans[i]);
        }
    }
    return 0;
}
