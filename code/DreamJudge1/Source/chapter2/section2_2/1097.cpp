#include <stdio.h>
using namespace std;

/*
仍是短除法的思路,此时只需注意余数必须为自然数,更具体的,应为0或1,所以,
若计算机算出余数为负,应将商加1,然后得出为正的余数
*/
int main(){
    int m;
    while(scanf("%d",&m)!=EOF){
        if(m==0) printf("%d\n",0);
        else{
            int ans[100]={0};
            int cur=0;
            while(m!=0){
                int w=m%(-2);
                if(w<0){
                    int tmp=m;
                    m=m/(-2)+1;
                    ans[cur++]=tmp+2*m;
                }
                else{
                    ans[cur++]=w;
                    m/=(-2);
                }
            }
            for(int i=cur-1;i>=0;i--) printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
