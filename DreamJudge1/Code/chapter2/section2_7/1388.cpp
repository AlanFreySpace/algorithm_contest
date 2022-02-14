#include <stdio.h>
#include <map>
using namespace std;

int main(){//利用map解决查找问题
    int n,m,tmp;
    map<int,int> M;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            M[tmp]++;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&tmp);
            if(M[tmp]!=0) printf("YES\n");
            else printf("NO\n");
        }
        M.clear();
    }
}
