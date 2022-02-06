#include <stdio.h>
using namespace std;

/*
应将价格都扩大3倍更精确(未这样处理)
*/
int main(){
    int n;
    double xper=5,yper=3,zper=(double)1/3;
    while(scanf("%d",&n)!=EOF){
        int maxx=n/xper;
        for(int i=0;i<=100&&i<=xper;i++){
            int maxy=(n-5*i)/yper;
            for(int j=0;i+j<=100&&j<=maxy;j++){
                int k=100-i-j;
                if(xper*i+yper*j+zper*k<=n)
                    printf("%s%d%s%d%s%d\n","x=",i,",y=",j,",z=",k);
            }
        }
    }
    return 0;
}
