#include <stdio.h>
#include <map>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int reader[205]={0};
        map<int,int> book;
        int tmp;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            reader[i]=tmp;
            book[tmp]++;
        }
        for(int i=0;i<n;i++){
            if(book[reader[i]]==1) printf("BeiJu\n");
            else printf("%d\n",book[reader[i]]-1);
        }
    }
    return 0;
}
