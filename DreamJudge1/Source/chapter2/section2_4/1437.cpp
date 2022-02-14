#include <stdio.h>
using namespace std;

int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
       int year,month,day;
       scanf("%d%d%d",&year,&month,&day);
       if(day<d[month]) printf("%04d-%02d-%02d\n",year,month,day+1);
       else if(day==d[month]){
         if(month<12) printf("%04d-%02d-%02d\n",year,month+1,1);
         else printf("%04d-%02d-%02d\n",year+1,1,1);
       }
    }
    return 0;
}
