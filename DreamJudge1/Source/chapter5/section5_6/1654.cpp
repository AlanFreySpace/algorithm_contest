#include <stdio.h>
using namespace std;

struct Node{
    int parent=-1;
    int depth=1;
}node[100];
//思路和1492题相同,还比1492题简单不少
int main(){
    int t,n,m,l,r;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d%d",&n,&m);
        for(int j=1;j<=n;j++){
            scanf("%d%d",&l,&r);
            if(l!=-1){
                node[l].parent=j;
                node[l].depth=node[j].depth+1;
            }
            if(r!=-1){
                node[r].parent=j;
                node[r].depth=node[j].depth+1;
            }
        }

        int par1,par2,index1,index2;
        for(int j=0;j<m;j++){
            index1=0;
            index2=0;
            scanf("%d%d",&par1,&par2);
            while(par1!=par2){
                if(node[par1].depth<node[par2].depth){
                    par2=node[par2].parent;
                    index2++;
                }
                else if(node[par1].depth>node[par2].depth){
                    par1=node[par1].parent;
                    index1++;
                }
                else{
                    par2=node[par2].parent;
                    index2++;
                    par1=node[par1].parent;
                    index1++;
                }
            }
            int ans=index1+index2;
            printf("%d\n",ans);
        }
    }
    return 0;
}
