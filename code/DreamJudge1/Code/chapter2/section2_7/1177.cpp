#include <stdio.h>
#include <string.h>
using namespace std;

int reader[1000]={0};//����iϲ������
int book[201]={0};//��i�м�����ϲ��

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
            if(book[reader[i]]==1) printf("BeiJu\n");//ע���Сд
            else printf("%d\n",book[reader[i]]-1);
        }
        memset(book,0,201*sizeof(int));//ע��memset�÷�
    }
    return 0;
}
