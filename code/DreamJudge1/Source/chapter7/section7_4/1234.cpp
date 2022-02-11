#include <stdio.h>
#include <algorithm>
using namespace std;
//��������,��ϡ��ͼ,Ӧ����kruskal�㷨
struct edge{
    int u,v,w;
}e[105];

bool cmp(edge e1,edge e2){
    return e1.w<e2.w;
}

char vil1,vil2;
int n,m,tmp,cost,s[30];//n�Ǵ�ׯ����,m�ǵ�·������

int Get(int x){
    int r=s[x];
    while(r!=s[r]) r=s[r];
    int i=x,j;
    while(i!=r){
        j=s[i];
        s[i]=r;
        i=j;
    }
    return r;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        m=0;
        for(int i=0;i<n;i++) s[i]=i;
        for(int i=1;i<n;i++){//����ͼ
            getchar();//ע��scanf("%c")��ѻس��Ϳո����ַ�,Ҫ��getchar������
            scanf("%c%d",&vil1,&tmp);
            for(int j=0;j<tmp;j++){
                getchar();
                scanf("%c%d",&vil2,&cost);
                e[m].u=vil1-'A';
                e[m].v=vil2-'A';
                e[m++].w=cost;
            }
        }

        int ans=0,flag=n;
        sort(e,e+m,cmp);
        for(int i=0;i<m;i++){
            int a=Get(e[i].u),b=Get(e[i].v);
            if(a==b) continue;
            flag--;
            s[a]=b;
            ans+=e[i].w;
            if(flag==1) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
