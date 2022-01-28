#include <stdio.h>
using namespace std;

int d[605];

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        for(int i=0;i<n;i++) scanf("%d",&d[i]);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++)
                if(gcd(d[i],d[j])==1) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
