#include <stdio.h>
using namespace std;

int n,m,ans;
int s[1005];

int Get(int x){
    int r=s[x];
    while(r!=s[r]) r=s[r];//找到根
    int i=x,j;
    while(i!=r){//路径压缩
        j=s[i];
        s[i]=r;
        i=j;
    }
    return r;
}

void Merge(int x,int y){
    int r1=Get(x),r2=Get(y);
    if(r1!=r2){//每发生一次合并,所需道路减1
        s[r1]=r2;
        ans--;
    }
}

int main(){
    while(scanf("%d",&n)){
        if(n==0) break;
        scanf("%d",&m);
        for(int i=1;i<=n;i++) s[i]=i;//初始化集合
        int tmp1,tmp2;
        ans=n-1;
        for(int i=0;i<m;i++){
            scanf("%d%d",&tmp1,&tmp2);
            Merge(tmp1,tmp2);
        }
        printf("%d\n",ans);
    }
    return 0;
}
