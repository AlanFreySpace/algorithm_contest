#include <stdio.h>
using namespace std;
/*
�ҹ��ɵ���Ŀ,ע��Ӧ��printf("%-4d",ans[i][j]);
��ʽ�����������-4��ʾÿ������ռ4����,�������
����Ϊ4�����Ҷ���
*/
int main(){
    int n;
    int ans[20][20];
    while(scanf("%d",&n)!=EOF){
        int num=1;
        for(int i=0;i<=n/2;i++){//����������Ĺ��ɷ�����
            for(int j=i;j<n-i;j++) ans[j][i]=num++;
            for(int j=i+1;j<n-i;j++) ans[n-i-1][j]=num++;
            for(int j=n-i-2;j>=i;j--) ans[j][n-i-1]=num++;
            for(int j=n-i-2;j>i;j--) ans[i][j]=num++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                printf("%-4d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
