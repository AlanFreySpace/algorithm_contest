#include <stdio.h>
using namespace std;

int main(){
    int n,a,b,c;
    while(scanf("%d",&n)!=EOF){
        int total=0,first=0,last=0,per=0,tmp=0;
        scanf("%d%d%d",&a,&b,&c);
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                total=i*10000+a*1000+b*100+c*10+j;
                tmp=total%n;
                if(tmp==0){
                    first=i;
                    last=j;
                    per=total/n;
                }
            }
        }
        if(first!=0) printf("%d %d %d\n",first,last,per);
        else printf("0\n");
    }
    return 0;
}
