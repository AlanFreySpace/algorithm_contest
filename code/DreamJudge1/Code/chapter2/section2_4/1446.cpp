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
            if(month==12&&day==31){//��������
                year++;
                if(isyear(year)&&n>=366) n-=366;
                else if(!isyear(year)&&n>=365) n-=365;
                else{
                    month=1;//ע�ⲻҪ��������
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
            else{//�ǿ������(����ת��Ϊ����,�����ڱ����־ͽ���)
               if(isyear(year)) d[2]=29;
               if(d[month]-day>=n){//�����㹻,�ڱ����ֽ���
                    day+=n;
                    n=0;
               }
               else{//���²���
                    n-=(d[month]-day);
                    if(month==12) day=31;//תΪ����
                    else{
                        month++;
                        for(int j=month;d[j]<n&&j<12;j++){
                            month=j+1;
                            n-=d[j];
                        }
                        if(d[month]>=n){//�ڱ����ֽ���
                            day=n;
                            n=0;
                        }
                        else{//תΪ����
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
