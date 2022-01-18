#include <stdio.h>
using namespace std;
//反序数知识点应用
int main(){
    for(int i=1000;i<1200;i++){
        int N=i;
        int ans=0;
        for(int j=0;j<4;j++){
            int cur=N%10;
            ans=ans*10+cur;
            N=N/10;
        }
        if(ans==9*i) printf("%d\n",i);
    }
    return 0;
}
