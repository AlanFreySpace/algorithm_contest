#include <stdio.h>
using namespace std;

int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int y,n;
    while(scanf("%d%d",&y,&n)!=EOF){
        if((y%400==0)||(y%4==0&&y%100!=0)) d[2]=29;
        int month,day;
        for(int i=1;i<=12;i++){
            if(d[i]<n) n-=d[i];
            else{
                month=i;
                day=n;
                break;
            }
        }
        d[2]=28;
        printf("%04d-%02d-%02d\n",y,month,day);//注意控制输出格式
    }
    return 0;
}
