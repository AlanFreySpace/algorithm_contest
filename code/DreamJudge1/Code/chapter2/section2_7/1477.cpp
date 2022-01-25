#include <stdio.h>
#include <map>
using namespace std;

int main(){
    int n,q;
    map<int,int> M;
    scanf("%d",&n);
    int tmp;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        M[tmp]++;//完成了两个动作:初始化了M[tmp]=0 然后M[tmp]++
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&tmp);
        if(M[tmp]!=0) printf("find\n");
        else{
            printf("no\n");
            M[tmp]++;
        }
    }
    return 0;
}
