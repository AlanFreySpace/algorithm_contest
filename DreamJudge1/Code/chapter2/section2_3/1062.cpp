#include <stdio.h>
using namespace std;

/*
�������:���ʾ����ҹ�����
*/
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) return 0;
        else{
            int ans[21][21]={0};//��ʼ������������Ԫ��Ϊ0
            for(int i=0;i<n;i++){
                ans[i][0]=1;
                for(int j=1;j<=i;j++) ans[i][j]=ans[i-1][j-1]+ans[i-1][j];//����
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<=i;j++) printf("%d ",ans[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
