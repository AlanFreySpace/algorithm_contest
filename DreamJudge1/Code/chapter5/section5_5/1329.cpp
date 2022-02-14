#include <stdio.h>
#include <map>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        map<int,int> M;
        int tmp;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            M[tmp]++;
        }
        int score;
        scanf("%d",&score);
        printf("%d\n",M[score]);
    }
    return 0;
}
