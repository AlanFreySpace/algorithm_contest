#include <stdio.h>
using namespace std;

int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

//判断是否为闰年,是则返回true
bool isyear(int a){
    if((a%400==0)||(a%4==0&&a%100!=0)) return true;
    return false;
}

int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a>b){//保证a<=b
            int tmp=a;
            a=b;
            b=tmp;
        }
        //得到年月日
        /*
        可用这种方法指定int长度,避免分离年月日
        scanf ("%4d%2d%2d",&year,&month,&day);
        */
        int day1=a%100,day2=b%100;
        a/=100;
        b/=100;
        int month1=a%100,month2=b%100;
        int year1=a/100,year2=b/100;

        int ans=0;
        for(int i=year1+1;i<year2;i++){
            if(isyear(i)) ans+=366;
            else ans+=365;
        }
        if(year1==year2){
            if(isyear(year1)) d[2]=29;
            if(month1==month2) ans=day2-day1+1;
            else{
                for(int i=month1+1;i<month2;i++) ans+=d[i];
                ans+=(day2+d[month1]-day1+1);
            }
            d[2]=28;
        }
        else{
            if(isyear(year1)) d[2]=29;
            for(int i=month1+1;i<=12;i++) ans+=d[i];
            ans+=(d[month1]-day1+1);
            if(!isyear(year2)) d[2]=28;
            for(int i=1;i<month2;i++) ans+=d[i];
            ans+=day2;
            d[2]=28;
        }
        printf("%d\n",ans);
    }
    return 0;
}
