#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

struct Node{
    int parent=-1;//父节点
    int depth=1;//该节点所在深度
}node[1000];

struct Query{
    int last;
    int priority;
}query[100];

bool cmp(Query a,Query b){
    return a.priority<b.priority;
}

int main(){
    int n,m;
    scanf("%d",&n);
    int par,son;
    for(int i=0;i<n;i++){
        scanf("%d",&par);
        for(int j=0;j<3;j++){
            scanf("%d",&son);
            if(son!=-1){
                node[son].parent=par;
                node[son].depth=node[par].depth+1;
            }
        }
    }
    /*
    for(int i=0;i<1000;i++){
        if(node[i].parent!=-1)
            printf("%d %d %d\n",i,node[i].parent,node[i].depth);
    }
    */
    scanf("%d",&m);
    int tmp1,tmp2;
    for(int i=0;i<m;i++)
        scanf("%d%d",&query[i].last,&query[i].priority);
    sort(query,query+m,cmp);
    /*
    for(int i=0;i<m;i++)
        printf("%d %d\n",query[i].last,query[i].priority);
    */
    int path1[100],path2[100];
    int index1=0,index2=0,par1,par2;
    path1[index1]=query[0].last;
    par1=node[path1[index1++]].parent;
    while(par1!=-1){
        path1[index1]=par1;
        par1=node[path1[index1++]].parent;
    }
    //for(int i=index1-1;i>=0;i--) printf("%d ",path1[i]);
    for(int i=1;i<m;i++){
        index1=0;
        index2=0;
        path1[index1]=path1[1];
        path2[index2]=query[i].last;
    }
    return 0;
}
