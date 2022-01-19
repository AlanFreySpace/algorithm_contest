#include <stdio.h>
using namespace std;

int a[100][100],tmp[100][100];

//顺时针旋转90度
void actA(int n,int m){
    for(int i=n-1;i>=0;i--)
        for(int j=0;j<m;j++) tmp[j][i]=a[n-i-1][j];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) a[i][j]=tmp[i][j];
}

//逆时针旋转90度
void actB(int n,int m){
    for(int i=0;i<n;i++)
        for(int j=m-1;j>=0;j--) tmp[j][i]=a[i][m-j-1];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) a[i][j]=tmp[i][j];
}

//沿纵向对称轴翻折
void actC(int n,int m){
    for(int i=0;i<n;i++)
        for(int j=0;j<m/2;j++){
            int tmp=a[i][j];
            a[i][j]=a[i][m-j-1];
            a[i][m-j-1]=tmp;
        }
}

int main(){
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
        }
        int act;
        for(int i=0;i<k;i++){
            scanf("%d",&act);
            if(act==1){
                actA(n,m);
                int v=n;
                n=m;
                m=v;
            }
            else if(act==3){
                actB(n,m);
                int v=n;
                n=m;
                m=v;
            }
            else actC(n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
