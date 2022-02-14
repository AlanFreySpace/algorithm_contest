#include <stdio.h>
#include <algorithm>
using namespace std;

/*
注意下面代码:如果不进行强制类型转换则结果为0
int x=1,y=4;
double v=(double)x/y;
printf("%llf",v);
*/

struct country{
    int id;//用于标记country的初始顺序
    int gold,medal,people;//金牌数、奖牌数、人口数
    double gPer,mPer;//金牌人口比、奖牌人口比
    int ranks[5];//四种排名方式得到的排名
};

country c[1000];
country t[1000];

bool cmp(country a,country b){
    return a.id<b.id;
}

bool cmp1(country a,country b){
    return a.gold>b.gold;
}

bool cmp2(country a,country b){
    return a.medal>b.medal;
}

bool cmp3(country a,country b){
    return a.gPer>b.gPer;
}

bool cmp4(country a,country b){
    return a.mPer>b.mPer;
}

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&c[i].gold,&c[i].medal,&c[i].people);
            c[i].gPer=(double)c[i].gold/c[i].people;
            c[i].mPer=(double)c[i].medal/c[i].people;
            c[i].id=i;
        }
        int index;
        for(int i=0;i<m;i++){
            scanf("%d",&index);
            t[i]=c[index];
        }

        sort(t,t+m,cmp1);
        int r=1;
        t[0].ranks[1]=r;
        for(int i=1;i<m;i++){//注意排名的代码如何写简单
            if(t[i].gold==t[i-1].gold) t[i].ranks[1]=r;
            else{
                t[i].ranks[1]=i+1;
                r=i+1;
            }
        }

        sort(t,t+m,cmp2);
        r=1;
        t[0].ranks[2]=r;
        for(int i=1;i<m;i++){
            if(t[i].medal==t[i-1].medal) t[i].ranks[2]=r;
            else{
                t[i].ranks[2]=i+1;
                r=i+1;
            }
        }

        sort(t,t+m,cmp3);
        r=1;
        t[0].ranks[3]=r;
        for(int i=1;i<m;i++){
            if(t[i].gPer==t[i-1].gPer) t[i].ranks[3]=r;
            else{
                t[i].ranks[3]=i+1;
                r=i+1;
            }
        }

        sort(t,t+m,cmp4);
        r=1;
        t[0].ranks[4]=r;
        for(int i=1;i<m;i++){
            if(t[i].mPer==t[i-1].mPer) t[i].ranks[4]=r;
            else{
                t[i].ranks[4]=i+1;
                r=i+1;
            }
        }

        sort(t,t+m,cmp);
        for(int i=0;i<m;i++){
            int way=1;
            for(int j=2;j<=4;j++)
                if(t[i].ranks[j]<t[i].ranks[way]) way=j;
            printf("%d:%d\n",t[i].ranks[way],way);
        }
        printf("\n");
    }
    return 0;
}
