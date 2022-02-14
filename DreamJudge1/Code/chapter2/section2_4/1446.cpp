#include <stdio.h>
using namespace std;

int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isyear(int n){
    if((n%400==0)||(n%4==0&&n%100!=0)) return true;
    return false;
}

int main(){
    int m,year,month,day,n;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&year,&month,&day,&n);
        while(n>0){
            if(month==12&&day==31){//跨年的情况
                year++;
                if(isyear(year)&&n>=366) n-=366;
                else if(!isyear(year)&&n>=365) n-=365;
                else{
                    month=1;//注意不要忘更新月
                    if(isyear(year)) d[2]=29;
                    for(int j=1;d[j]<n;j++){
                        month=j+1;
                        n-=d[j];
                    }
                    day=n;
                    n=0;
                    d[2]=28;
                }
            }
            else{//非跨年情况(均将转化为跨年,或者在本部分就结束)
               if(isyear(year)) d[2]=29;
               if(d[month]-day>=n){//本月足够,在本部分结束
                    day+=n;
                    n=0;
               }
               else{//本月不够
                    n-=(d[month]-day);
                    if(month==12) day=31;//转为跨年
                    else{
                        month++;
                        for(int j=month;d[j]<n&&j<12;j++){
                            month=j+1;
                            n-=d[j];
                        }
                        if(d[month]>=n){//在本部分结束
                            day=n;
                            n=0;
                        }
                        else{//转为跨年
                            day=31;
                            n-=31;
                        }
                    }
               }
               d[2]=28;
            }
        }
        printf("%04d-%02d-%02d\n",year,month,day);
    }
    return 0;
}
