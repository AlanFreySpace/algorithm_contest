#include <stdio.h>
using namespace std;

/*
���Ƕ̳�����˼·,��ʱֻ��ע����������Ϊ��Ȼ��,�������,ӦΪ0��1,����,
��������������Ϊ��,Ӧ���̼�1,Ȼ��ó�Ϊ��������
*/
int main(){
    int m;
    while(scanf("%d",&m)!=EOF){
        if(m==0) printf("%d\n",0);
        else{
            int ans[100]={0};
            int cur=0;
            while(m!=0){
                int w=m%(-2);
                if(w<0){
                    int tmp=m;
                    m=m/(-2)+1;
                    ans[cur++]=tmp+2*m;
                }
                else{
                    ans[cur++]=w;
                    m/=(-2);
                }
            }
            for(int i=cur-1;i>=0;i--) printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
