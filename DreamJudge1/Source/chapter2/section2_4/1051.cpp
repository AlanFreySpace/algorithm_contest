#include <stdio.h>
using namespace std;

struct node{
    int year,month,day;
}p;

int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

/*
闰年:公元年分非4的倍数为平年。公元年分为4的倍数但非100的倍数为闰年。
公元年分为100的倍数但非400的倍数为平年。公元年分为400的倍数为闰年。
*/
int main(){
    while(scanf("%d%d%d",&p.year,&p.month,&p.day)!=EOF){
        int ans=0;
        int flag=1;
        if(p.year<0) flag=0;
        if(p.month<1||p.month>12) flag=0;
        if(!flag) printf("Input error!\n");
        else{
           if((p.year%400==0)||(p.year%4==0&&p.year%100!=0)) d[2]=29;
           if(p.day<0||p.day>d[p.month]) flag=0;
           if(!flag) printf("Input error!\n");
           else{
             for(int i=1;i<p.month;i++) ans+=d[i];
             ans+=p.day;
             printf("%d\n",ans);
           }
           d[2]=28;
        }
    }
    return 0;
}
