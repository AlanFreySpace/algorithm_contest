#include <stdio.h>
#include <string.h>
using namespace std;

int reader[1000]={0};//读者i喜欢的书
int book[201]={0};//书i有几个人喜欢

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int tmp;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            reader[i]=tmp;
            book[tmp]++;
        }
        for(int i=0;i<n;i++){
            if(book[reader[i]]==1) printf("BeiJu\n");//注意大小写
            else printf("%d\n",book[reader[i]]-1);
        }
        memset(book,0,201*sizeof(int));//注意memset用法
    }
    return 0;
}
