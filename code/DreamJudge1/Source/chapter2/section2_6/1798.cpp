#include <stdio.h>
#include <algorithm>
using namespace std;

/*
����ؼ�:ע����ζ�ȡ�����ŵ�����
*/
int main(){
    int a[1000];
    int i=0,tmp;
    while(scanf("%d",&tmp)!=EOF){//��ȡint,ע�����ﲻҪд��scanf("%d",&a[i++])!=EOF
         a[i]=tmp;   //������Ϊ��ͬ�������Ը���䴦��ͬ,�еı���������EOFʱ���i��1
         i++;        //�еĲ���
         if(getchar()=='\n') break;//��ȡ\n�����з��򶺺�
    }
    sort(a,a+i);
    for(int j=0;j<i;j++){
        printf("%d ",a[j]);
        if(j%4==3) printf("\n");
    }
    return 0;
}
