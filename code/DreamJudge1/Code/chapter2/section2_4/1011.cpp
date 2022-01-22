#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int d[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
string a[7]={"Sunday","Monday","Thesday","Wednesday",
             "Thursday","Friday","Saturday"};

int main(){
    int month,day;
    while(scanf("%d%d",&month,&day)!=EOF){
        int sum=0;
        if(month==4) sum=day-12;
        else{
            sum=18;
            for(int i=5;i<month;i++) sum+=d[i];
            sum+=day;
        }
        sum+=4;
        cout<<a[sum%7]<<endl;
    }
    return 0;
}
