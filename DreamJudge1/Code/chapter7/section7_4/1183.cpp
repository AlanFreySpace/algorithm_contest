#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct point{
    double x,y;//��¼�������
}p[105];

int n;
int flag[105];
double matrix[105][105],d[105];
//����ͼӦ����prim�㷨���
void prim(){
    d[1]=0.;
    for(int i=1;i<n;i++){
        int x=0;
        for(int j=1;j<=n;j++)
            if(!flag[j]&&d[j]<d[x]) x=j;
        flag[x]=1;
        for(int j=1;j<=n;j++)
            if(!flag[j]) d[j]=min(d[j],matrix[x][j]);
    }
}

/*
ע����0x77��ʼ��double��ʾdouble������,��0x3f��ʼ��int��ʾint������
hypot���ڼ���������֮�����,�����¾�273ҳ
*/
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(matrix,0x77,sizeof(matrix));
        memset(d,0x77,sizeof(d));
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                matrix[i][j]=matrix[j][i]=hypot(p[i].x-p[j].x,p[i].y-p[j].y);
        prim();
        double ans=0.;
        for(int i=1;i<=n;i++) ans+=d[i];
        printf("%.2lf\n",ans);
    }
    return 0;
}
