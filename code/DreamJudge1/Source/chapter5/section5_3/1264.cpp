#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF){
        int ans=0,tmp=1;
        while(m<n){//不断向最右侧走
            ans+=tmp;
            tmp*=2;
            m=2*m+1;
        }
        int h1=log(m)/log(2),h2=log(n)/log(2);
        if(h1==h2){//来到和n同一层,ans需要再加些项
            if(m==n) ans+=tmp;
            else ans+=(tmp+n-m);
        }
        printf("%d\n",ans);
    }
    return 0;
}
