#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//Ӧ��prim�㷨�����С����������
int n,m,x,y,w;
int matrix[105][105],flag[105],d[105];
//���¾�254+���϶�363
int prim(){
    d[1]=0;
    for(int i=1;i<=m;i++){
        int x=0;
        for(int j=1;j<=m;j++)//����������С�������еĶ���x
            if(!flag[j]&&d[j]<d[x]) x=j;
        if(x!=0){//����ɹ�,Ӧ����������С�������ж�����
            flag[x]=1;//ʣ�������֮���Ȩ����С�ı�
            for(int j=1;j<=m;j++)
                if(!flag[j]) d[j]=min(d[j],matrix[x][j]);
        }
        else return 0;//x==0ʱ������ʧ��
    }
    return 1;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0) break;
        memset(matrix,0x3f,sizeof(matrix));
        memset(flag,0,sizeof(flag));
        memset(d,0x3f,sizeof(d));
        //�����ڽӾ���
        for(int i=1;i<=m;i++) matrix[i][i]=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&w);
            matrix[x][y]=min(w,matrix[x][y]);//ע����ر���Ӧȡ��С��
            matrix[y][x]=matrix[x][y];
        }
        int con=prim();
        if(!con) printf("?\n");
        else{
            int ans=0;
            for(int i=1;i<=m;i++) ans+=d[i];
            printf("%d\n",ans);
        }
    }
    return 0;
}
