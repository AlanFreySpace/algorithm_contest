#include <stdio.h>
using namespace std;

int a[9][9],b[9][9],tmp[9][9];

/*
���Ȿ���ϻ����ҹ�����,�ҳ���ת���Ԫ�ض�Ӧ��ϵ����
*/

//����˳ʱ����ת90��
void rot(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) tmp[j][n-i-1]=a[i][j];//����
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) a[i][j]=tmp[i][j];
    }
}
//�Ƚ�������Ԫ���Ƿ���ͬ
bool compare(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=b[i][j]) return false;
        }
    }
    return true;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) scanf("%d",&a[i][j]);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) scanf("%d",&b[i][j]);

        int flag=0;
        for(int i=0;i<4;i++){//������ͣ��˳ʱ����ת90��(����3��)
            if(!flag){
                if(compare(n)){
                    printf("%d\n",90*i);
                    flag=1;
                }
                else rot(n);
            }
            else break;
        }
        if(!flag) printf("-1\n");
    }
    return 0;
}
