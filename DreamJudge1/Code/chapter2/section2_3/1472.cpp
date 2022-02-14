#include <stdio.h>
#include <string.h>
using namespace std;

int tmp[4][4];
int a[4][4];
int ans[4][4];

/*
注意该游戏的规则:下面的输入要体会好:
输入:         输出:
4
0 0 2 2       0 0 0 4
2 0 0 2       0 0 0 4
0 0 4 8       0 0 4 8
0 0 4 8       0 0 4 8
*/

void up(){
    for(int i=0;i<4;i++){//去掉中间的0
        int cur=0;
        for(int j=0;j<4;j++){
            if(tmp[j][i]!=0) a[cur++][i]=tmp[j][i];
        }
    }
    for(int i=0;i<4;i++){//碰撞合并
        int t=0;
        while(t<3){
            if(a[t][i]==a[t+1][i]){
                a[t][i]*=2;
                a[t+1][i]=0;
                t+=2;
            }
            else t++;
        }
    }
    for(int i=0;i<4;i++){//去掉中间的0
        int cur=0;
        for(int j=0;j<4;j++){
            if(a[j][i]!=0) ans[cur++][i]=a[j][i];
        }
    }
}

void down(){
    for(int i=0;i<4;i++){
        int cur=3;
        for(int j=3;j>=0;j--){
            if(tmp[j][i]!=0) a[cur--][i]=tmp[j][i];
        }
    }
    for(int i=0;i<4;i++){
        int t=3;
        while(t>0){
            if(a[t][i]==a[t-1][i]){
                a[t][i]*=2;
                a[t-1][i]=0;
                t-=2;
            }
            else t--;
        }
    }
    for(int i=0;i<4;i++){
        int cur=3;
        for(int j=3;j>=0;j--){
            if(a[j][i]!=0) ans[cur--][i]=a[j][i];
        }
    }
}

void left(){
    for(int i=0;i<4;i++){
        int cur=0;
        for(int j=0;j<4;j++){
            if(tmp[i][j]!=0) a[i][cur++]=tmp[i][j];
        }
    }
    for(int i=0;i<4;i++){
        int t=0;
        while(t<3){
            if(a[i][t]==a[i][t+1]){
                a[i][t]*=2;
                a[i][t+1]=0;
                t+=2;
            }
            else t++;
        }
    }
    for(int i=0;i<4;i++){
        int cur=0;
        for(int j=0;j<4;j++){
            if(a[i][j]!=0) ans[i][cur++]=a[i][j];
        }
    }
}

void right(){
    for(int i=0;i<4;i++){
        int cur=3;
        for(int j=3;j>=0;j--){
            if(tmp[i][j]!=0) a[i][cur--]=tmp[i][j];
        }
    }
    for(int i=0;i<4;i++){
        int t=3;
        while(t>0){
            if(a[i][t]==a[i][t-1]){
                a[i][t]*=2;
                a[i][t-1]=0;
                t-=2;
            }
            else t--;
        }
    }
    for(int i=0;i<4;i++){
        int cur=3;
        for(int j=3;j>=0;j--){
            if(a[i][j]!=0) ans[i][cur--]=a[i][j];
        }
    }
}

int main(){
    int act;
    while(scanf("%d",&act)!=EOF){
        memset(a,0,64);
        memset(ans,0,64);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++) scanf("%d",&tmp[i][j]);
        if(act==1) up();
        else if(act==2) down();
        else if(act==3) left();
        else right();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++) printf("%d ",ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}
