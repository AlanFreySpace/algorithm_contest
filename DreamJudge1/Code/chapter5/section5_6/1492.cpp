#include <stdio.h>
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
/*
思路:从起始和终止节点分别往前回溯,回溯时应让深度深的节点先回溯,直到两者
深度相同,再回溯至公共节点即可
*/
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

    scanf("%d",&m);
    int tmp1,tmp2;
    for(int i=0;i<m;i++)
        scanf("%d%d",&query[i].last,&query[i].priority);
    sort(query,query+m,cmp);

    int path1[100],path2[100];
    int index1=0,index2=0,par1,par2;
    par2=query[0].last;
    while(par2!=-1){
        path2[index2++]=par2;
        par2=node[par2].parent;
    }
    for(int i=index2-1;i>=0;i--) printf("%d ",path2[i]);
    printf("\n");
    for(int i=1;i<m;i++){
        index1=0;
        index2=0;
        par1=path2[1];
        par2=query[i].last;
        path1[index1++]=par1;
        path2[index2++]=par2;
        while(par1!=par2){
            if(node[par1].depth>node[par2].depth){
                par1=node[par1].parent;
                path1[index1++]=par1;
            }
            else if(node[par1].depth<node[par2].depth){
                par2=node[par2].parent;
                path2[index2++]=par2;
            }
            else{
                par1=node[par1].parent;
                path1[index1++]=par1;
                par2=node[par2].parent;
                path2[index2++]=par2;
            }
        }
        for(int j=0;j<index1;j++)
            printf("%d ",path1[j]);
        for(int j=index2-2;j>=0;j--)
            printf("%d ",path2[j]);
        printf("\n");
    }
    index2=0;
    par2=path2[1];
    while(par2!=-1){
        path2[index2++]=par2;
        par2=node[par2].parent;
    }
    for(int i=0;i<index2;i++)
        printf("%d ",path2[i]);
    return 0;
}
