#include <stdio.h>
using namespace std;

struct node{
    int year,month,day;
}p;

int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

/*
����:��Ԫ��ַ�4�ı���Ϊƽ�ꡣ��Ԫ���Ϊ4�ı�������100�ı���Ϊ���ꡣ
��Ԫ���Ϊ100�ı�������400�ı���Ϊƽ�ꡣ��Ԫ���Ϊ400�ı���Ϊ���ꡣ
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
