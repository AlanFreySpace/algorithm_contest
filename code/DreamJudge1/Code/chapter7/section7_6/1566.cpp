#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n,m,x,y;
int matrix[505][505],in[505];
vector<int> v[505];

void topo(){
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;i++)
        if(!in[i]) q.push(i);//���Ϊ0�Ķ���
    while(!q.empty()){
        int now=q.top();
        printf("%d ",now);
        q.pop();
        for(int i=0;i<v[now].size();i++){
            int j=v[now][i];
            in[j]--;//���Ϊ0������ڽӵ���ȶ���1
            if(!in[j]) q.push(j);//����1���Ϊ0 ���
        }
    }
    printf("\n");
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(matrix,0,sizeof(matrix));
        memset(in,0,sizeof(in));
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            matrix[x][y]=1;
            v[x].push_back(y);//�洢��(x,y)
            in[y]++;//ͳ�����
        }
        topo();
    }
    return 0;
}
