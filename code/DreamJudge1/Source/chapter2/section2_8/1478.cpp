#include <stdio.h>
#include <algorithm>
using namespace std;

struct drink{
    int m,w;//m:总量 w:总价
}d[1005];

bool cmp(drink a,drink b){
    return (double)a.w/a.m<(double)b.w/b.m;
}

int main(){
    double x;
    int n;
    /*
    注意读入时数据类型别写错了:
    对于float类型的变量，printf()中的说明符可以用%f或%lf，
    而scanf()中的说明符则只能用%f
    对于double类型的变量，printf()中的说明符可以用%f或%lf，
    而scanf()中的说明符则只能用%lf
    对于long double类型的变量，printf()中的说明符可以用%Lf，
    而scanf()中的说明符则只能用%Lf。
    */
    while(scanf("%lf%d",&x,&n)!=EOF){
        if(x==-1&&n==-1) break;
        else{
            double ans=0;
            for(int i=0;i<n;i++) scanf("%d%d",&d[i].m,&d[i].w);
            sort(d,d+n,cmp);
            for(int i=0;i<n;i++){
                if(x>d[i].w){
                    x-=d[i].w;
                    ans+=d[i].m;
                    //printf("%s %.3lf\n","1",ans);
                }
                else if(x==d[i].w){
                    ans+=d[i].m;
                    //printf("%s %.3lf\n","2",ans);
                    break;
                }
                else{
                    double pw=(double)d[i].w/d[i].m;
                    ans+=(x/pw);
                    //printf("%s %.3lf\n","3",ans);
                    break;
                }
            }
            printf("%.3lf\n",ans);
        }
    }
    return 0;
}
